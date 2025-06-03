class No 
{
    public int elemento; // Conteudo do no.
    public No esq, dir; // Filhos da esq e dir.
    public int nivel; // Numero de niveis abaixo do no

    public No (int elemento) {
        this( elemento, null, null, 1 );
    } // end No ( )

    public No ( int elemento, No esq, No dir, int nivel ) 
    {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
        this.nivel = nivel;
    } // end No ( )

    public void setNivel ( ) {
        this.nivel = 1 + Math.max( getNivel( esq ), getNivel( dir ) );
    } // end setNivel ( )

    public static int getNivel ( No no ) {
        return ( ( no == null ) ? 0 : no.nivel );
    } // end getNivel ( )
} // end No

public class Avl 
{
    private No raiz; // Raiz da arvore.

    public Avl ( ) {
        raiz = null;
    } // end Avl ( )

    public void inserir ( int x ) {
        raiz = inserir( x, raiz );
    } // end inserir ( )

    private No inserir ( int x, No i ) 
    {
        if ( i == null ) {
            i = new No( x );
        } else if ( x < i.elemento ) {
            i.esq = inserir( x, i.esq );
        } else if ( x > i.elemento ) {
            i.dir = inserir( x, i.dir );
        } else {
            System.out.println( "[INSERIR] ERRO: Elemento Ja Existe!" );
        } // end else
        return ( balancear( i ) );
    } // end inserir ( )

    private No balancear ( No i ) 
    {
        if ( i != null ) {
            int fator = No.getNivel( i.dir ) - No.getNivel( i.esq );
            if ( Math.abs( fator ) <= 1 ) {
                i.setNivel( );
            } else if ( fator == 2 ) {
                int fatorFilhoDir = No.getNivel( i.dir.dir ) - No.getNivel( i.dir.esq );
                if ( fatorFilhoDir == -1 ) {
                    i.dir = rotacionarDir( i.dir );
                } // end if
                i = rotacionarEsq( i );
            } else if ( fator == -2 ) {
                int fatorFilhoEsq = No.getNivel( i.esq.dir ) - No.getNivel( i.esq.esq );
                if ( fatorFilhoEsq == 1 ) {
                    i.esq = rotacionarEsq( i.esq );
                } // end if
                i = rotacionarDir( i );
            } else {
                System.out.println( "[BALANCEAR] ERRO: No com Fator de Balanceamento Invalido!" );
            } // end else
        } // end if
        return ( i );
    } // end balancear ( )

    private No rotacionarDir ( No no ) 
    {
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
        noEsq.dir = no;
        no.esq = noEsqDir;
        no.setNivel( );
        noEsq.setNivel( );
        return ( noEsq );
    } // end rotacionarDir ( )

    private No rotacionarEsq ( No no ) 
    {
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
        noDir.esq = no;
        no.dir = noDirEsq;
        no.setNivel( );
        noDir.setNivel( );
        return ( noDir );
    } // end rotacionarEsq ( )

    public boolean pesquisar ( int x ) {
        return ( pesquisar( x, raiz ) );
    } // end pesquisar ( )

    private boolean pesquisar ( int x, No i ) 
    {
        boolean resp;
        if ( i == null ) {
            resp = false;
        } else if ( x == i.elemento ) {
            resp = true;
        } else if ( x < i.elemento ) {
            resp = pesquisar( x, i.esq );
        } else {
            resp = pesquisar( x, i.dir );
        } // end else
        return ( resp );
    } // end pesquisar ( )

    public void PreOrdem ( ) {
        PreOrdem( raiz );
    } // end PreOrdem ( )

    private void PreOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            System.out.print( i.elemento + " " );
            PreOrdem( i.esq );
            PreOrdem( i.dir );
        } // end if
    } // end PreOrdem ( )

    public void EmOrdem ( ) {
        EmOrdem( raiz );
    } // end EmOrdem ( )

    private void EmOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            EmOrdem( i.esq );
            System.out.print( i.elemento + " " );
            EmOrdem( i.dir );
        } // end if
    } // end EmOrdem ( )

    public void PosOrdem ( ) {
        PosOrdem( raiz );
    } // end PosOrdem ( )

    private void PosOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            PosOrdem( i.esq );
            PosOrdem( i.dir );
            System.out.print( i.elemento + " " );
        } // end if
    } // end PosOrdem ( )

    public void remover ( int x ) {
        raiz = remover( x, raiz );
    } // end remover ( )

    private No remover ( int x, No i ) 
    {
        if ( i == null ) {
            System.out.println( "[REMOVER] ERRO: Elemento Nao Existe!" );
        } else if ( x < i.elemento ) {
            i.esq = remover( x, i.esq );
        } else if ( x > i.elemento ) {
            i.dir = remover( x, i.dir );
        } else if ( i.dir == null ) {
            i = i.esq;
        } else if ( i.esq == null ) {
            i = i.dir;
        } else {
            i.esq = maiorEsq( i, i.esq );
        } // end else
        return ( balancear( i ) );
    } // end remover ( )

    private No maiorEsq ( No i, No j ) 
    {
        if ( j.dir != null ) {
            j.dir = maiorEsq( i, j.dir );
        } else {
            i.elemento = j.elemento;
            j = j.esq;
        } // end else
        return ( j );
    } // end maiorEsq ( )

} // end Avl