class Celula 
{
    public int elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    public Celula ( ) {
        this(0);
    } // end Celula ( )

    public Celula ( int elemento ) 
    {
        this.elemento = elemento;
        this.prox = null;
    } // end Celula ( )
} // end class Celula

public class Fila 
{
    Celula primeiro;
    Celula ultimo;

    public Fila ( )
    {
        primeiro = new Celula ( );
        ultimo = primeiro;
    } // end Fila ( )

    public void inserir ( int x )
    {
        ultimo.prox = new Celula( x );
        ultimo = ultimo.prox;
    } // end inserir ( )

    public int remover ( ) throws Exception
    {
        if( primeiro == ultimo ) {
            throw new Exception ( "[REMOVER] ERRO: Fila Vazia!" );
        } // end if
        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int resp = primeiro.elemento;
        tmp.prox = null;
        tmp = null;
        return ( resp );
    } // end remover ( )

    public void mostrar ( )
    {
        System.out.println( "[" );
        for ( Celula i = primeiro.prox; i != null; i = i.prox ) {
            System.out.print ( " " + i.elemento );
        } // end for
        System.out.println( " ]" );
    } // end mostrar ( )

    public boolean pesquisar ( int x )
    {
        boolean resp = false;
        for( Celula i = primeiro.prox; i != null; i = i.prox )
        {
            if( i.elemento == x )
            {
                resp = true;
                i = ultimo;
            } // end if
        } // end for
        return ( resp );
    } // end pesquisar ( )

    public int tamanho ( )
    {
        int tamanho = 0;
        for( Celula i = primeiro; i != ultimo; i = i.prox, tamanho++ );
        return ( tamanho );
    } // end tamanho ( )
} // end class Fila
