class No 
{
    boolean cor;
    int elemento;
    No esq, dir;

    public No ( ) {
        this(-1);
    } // end No ( )

    public No ( int elemento ) {
        this( elemento, false, null, null );
    } // end No ( )

    public No ( int elemento, boolean cor ) {
        this( elemento, cor, null, null );
    } // end No ( )

    public No ( int elemento, boolean cor, No esq, No dir ) 
    {
        this.cor = cor;
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    } // end No ( )
} // end class No

public class Bicolor 
{
    private No raiz; // Raiz da arvore.

    public Bicolor ( ) {
        raiz = null;
    } // end Bicolor ( )

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
        } // end if
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

    public void inserir ( int elemento ) throws Exception
    {
        // Se a arvore estiver vazia
        if ( raiz == null ) {
            raiz = new No(elemento);
        } else if (raiz.esq == null && raiz.dir == null) 
        {
            if ( elemento < raiz.elemento ) {
                raiz.esq = new No(elemento);
            } else {
                raiz.dir = new No(elemento);
            } // end if    
        } else if (raiz.esq == null) 
        {
            if ( elemento < raiz.elemento ) {
                raiz.esq = new No(elemento);
            } 
            else if (elemento < raiz.dir.elemento) 
            {
                raiz.esq = new No(raiz.elemento);
                raiz.elemento = elemento;
            } 
            else 
            {
                raiz.esq = new No(raiz.elemento);
                raiz.elemento = raiz.dir.elemento;
                raiz.dir.elemento = elemento;
            } // end if
            raiz.esq.cor = raiz.dir.cor = false;     
        } else if ( raiz.dir == null ) {
            if ( elemento > raiz.elemento ) {
                raiz.dir = new No(elemento);
            } 
            else if ( elemento > raiz.esq.elemento )
            {
                raiz.dir = new No(raiz.elemento);
                raiz.elemento = elemento;
            } 
            else 
            {
                raiz.dir = new No( raiz.elemento );
                raiz.elemento = raiz.esq.elemento;
                raiz.esq.elemento = elemento;
            }
            raiz.esq.cor = raiz.dir.cor = false;     
        } else {
            inserir(elemento, null, null, null, raiz);
        } // end if
        raiz.cor = false;
    } // end inserir ( )

    private void inserir ( int elemento, No bisavo, No avo, No pai, No filho ) throws Exception 
    {
        if ( filho == null ) 
        {
            if ( elemento < pai.elemento ) {
                filho = pai.esq = new No( elemento, true );
            } else {
                filho = pai.dir = new No( elemento, true );
            } // end if
            if ( pai.cor == true ) {
                balancear( bisavo, avo, pai, filho );
            } // end if
        } 
        else 
        {
            if ( filho.esq != null && filho.dir != null && filho.esq.cor == true && filho.dir.cor == true ) 
            {
                filho.cor = true;
                filho.esq.cor = filho.dir.cor = false;
                if ( filho == raiz ) {
                    filho.cor = false;
                } else if ( pai.cor == true ) {
                    balancear( bisavo, avo, pai, filho );
                } // end if
            } // end if
            if ( elemento < filho.elemento ) {
                inserir( elemento, avo, pai, filho, filho.esq );
            } else if ( elemento > filho.elemento ) {
                inserir( elemento, avo, pai, filho, filho.dir );
            } else {
                throw new Exception("[INSERIR] ERRO: Elemento repetido!");
            } // end if
        } // end if
    } // end inserir ( )

    private void balancear ( No bisavo, No avo, No pai, No i ) 
    {
        if ( pai.cor == true ) 
        {
            // Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
            if ( pai.elemento < avo.elemento ) 
            { 
                // rotacao a esquerda ou direita-esquerda
                if ( i.elemento < pai.elemento ) {
                    avo = rotacaoDir( avo );
                } else {
                    avo = rotacaoEsqDir( avo );
                } // end if
            } 
            else 
            { 
                // rotacao a direita ou esquerda-direita
                if ( i.elemento > pai.elemento ) {
                    avo = rotacaoEsq( avo );
                } else {
                    avo = rotacaoDirEsq( avo );
                } // end if
            } // end if

            if ( bisavo == null ) {
                raiz = avo;
            } 
            else 
            {
                if ( avo.elemento < bisavo.elemento ) {
                    bisavo.esq = avo;
                } else {
                    bisavo.dir = avo;
                } // end if
            } // end if

            avo.cor = false;
            avo.esq.cor = avo.dir.cor = true;
        } // end if
    } // end balancear ( )

    private No rotacaoDir ( No no ) 
    {
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
        noEsq.dir = no;
        no.esq = noEsqDir;
        return ( noEsq );
    } // end rotacaoDir ( )

    private No rotacaoEsq ( No no ) 
    {
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
        noDir.esq = no;
        no.dir = noDirEsq;
        return ( noDir );
    } // end rotacaoEsq ( )

    private No rotacaoDirEsq ( No no ) 
    {
        no.dir = rotacaoDir( no.dir );
        return ( rotacaoEsq( no ) );
    } // end rotacaoDirEsq ( )

    private No rotacaoEsqDir ( No no ) 
    {
        no.esq = rotacaoEsq( no.esq );
        return ( rotacaoDir( no ) );
    } // end rotacaoEsqDir ( )
    
} // end class Bicolor