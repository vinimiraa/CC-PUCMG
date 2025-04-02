class No
{
    public int elemento; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.

    public No ( int elemento ) {
        this(elemento, null, null);
    } // end No( )

    public No ( int elemento, No esq, No dir ) 
    {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    } // end No( )
} // end class No

public class ArvoreBinaria 
{
    private No raiz; // Raiz da arvore.

    public ArvoreBinaria ( ) {
        raiz = null;
    } // end ArvoreBinaria( )

    public boolean pesquisar ( int x ) {
        return ( pesquisar( x, raiz ) );
    } // end pesquisar( )

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
        } // end if
        return ( resp );
    } // end pesquisar( )

    public void inserir ( int x ) {
        raiz = inserir( x, raiz );
    } // end inserir( )

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
        } // end if
        return ( i );
    } // end inserir( )

    public void PreOrdem ( ) {
        PreOrdem( raiz );
    } // end PreOrdem( )

    private void PreOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            System.out.print( i.elemento + " " );
            PreOrdem( i.esq );
            PreOrdem( i.dir );
        } // end if
    } // end PreOrdem( )

    public void EmOrdem ( ) {
        EmOrdem( raiz );
    } // end EmOrdem( )

    private void EmOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            EmOrdem( i.esq );
            System.out.print( i.elemento + " " );
            EmOrdem( i.dir );
        } // end if
    } // end EmOrdem( )

    public void PosOrdem ( ) {
        PosOrdem( raiz );
    } // end PosOrdem( )

    private void PosOrdem ( No i ) 
    {
        if ( i != null ) 
        {
            PosOrdem( i.esq );
            PosOrdem( i.dir );
            System.out.print( i.elemento + " " );
        } // end if
    } // end PosOrdem( )

    public void remover ( int x ) {
        raiz = remover( x, raiz );
    } // end remover( )

    private No remover ( int x, No i ) 
    {
        if ( i == null ) {
            System.out.println( "[REMOVER] ERRO: Elemento Nao Encontrado!" );
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
        } // end if
        return ( i );
    } // end remover( )

    private No maiorEsq ( No i, No j ) 
    {
        if ( j.dir != null ) {
            j.dir = maiorEsq( i, j.dir );
        } else {
            i.elemento = j.elemento;
            j = j.esq;
        } // end if
        return ( j );
    } // end maiorEsq( )
    
} // end class ArvoreBinaria