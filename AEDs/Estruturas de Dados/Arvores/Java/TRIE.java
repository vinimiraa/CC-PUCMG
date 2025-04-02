class No 
{
    public char elemento;
    public final int tamanho = 255;
    public No[] prox;
    public boolean folha;

    public No ( ) {
        this( ' ' );
    } // end No( )

    public No ( char elemento ) 
    {
        this.elemento = elemento;
        prox = new No[tamanho];
        for( int i = 0; i < tamanho; i++ ) {
            prox[i] = null;
        } // end for
        folha = false;
    } // end No( )

    public static int hash ( char x ) {
        return (int) x;
    } // end hash( )
} // end class No

public class TRIE 
{
    private No raiz;

    public TRIE ( ) {
        raiz = new No( );
    } // end TRIE( )

    public boolean pesquisar ( String s ) throws Exception {
        return ( pesquisar( s, raiz, 0 ) );
    } // end pesquisar( )

    public boolean pesquisar ( String s, No no, int i ) throws Exception 
    {
        boolean resp = false;
        if ( no.prox[s.charAt(i)] == null ) {
            resp = false;
        } else if ( i == s.length() - 1 ) {
            resp = (no.prox[s.charAt(i)].folha == true);
        } else if ( i < s.length() - 1 ) {
            resp = pesquisar(s, no.prox[s.charAt(i)], i + 1);
        } else {
            throw new Exception( "[PESQUISAR] ERRO: Nao Foi Possivel Pesquisar" );
        } // end if
        return ( resp );
    } // end pesquisar( )

    public void inserir ( String s ) throws Exception {
        inserir( s, raiz, 0 );
    } // end inserir( )

    private void inserir ( String s, No no, int i ) throws Exception 
    {
        if( no.prox[s.charAt(i)] == null ) {
            no.prox[s.charAt(i)] = new No(s.charAt(i));
            if ( i == s.length() - 1 ) {
                no.prox[s.charAt(i)].folha = true;
            } else {
                inserir(s, no.prox[s.charAt(i)], i + 1);
            } // end if
        } else if ( no.prox[s.charAt(i)].folha == false && i < s.length() - 1 ) {
            inserir( s, no.prox[s.charAt(i)], i + 1 );
        } else {
            throw new Exception( "[INSERIR] ERRO: Nao Foi Possivel Inserir" );
        } // end if
    } // end inserir( )

    public void mostrar ( ) {
        mostrar( "", raiz );
    } // end mostrar( )

    public void mostrar ( String s, No no ) 
    {
        if ( no.folha == true ) {
            System.out.println( "Palavra: " + ( s + no.elemento ) );
        } 
        else 
        {
            for ( int i = 0; i < no.prox.length; i++ ) 
            {
                if ( no.prox[i] != null ) {
                    mostrar( s + no.elemento, no.prox[i] );
                } // end if
            } // end for
        } // end if
    } // end mostrar( )
} // end class TRIE
