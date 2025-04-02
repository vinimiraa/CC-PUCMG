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

public class Pilha 
{
    Celula topo;

    public Pilha ( ) {
        topo = null;
    } // end Pilha ( )

    public void inserir ( int x )
    {
        Celula tmp = new Celula ( x );
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    } // end inserir ( )

    public int remover ( ) throws Exception
    {
        if( topo == null ) {
            throw new Exception ( "[REMOVER] ERRO: Pilha Vazia!" );
        } // end if
        int resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return ( resp );
    } // end remover ( )

    public void mostrar ( )
    {
        System.out.print ( "[ " );
        for ( Celula i = topo; i != null; i = i.prox ) {
            System.out.print ( i.elemento + " " );
        } // end for
        System.out.println ( "] " );
    } // end mostrar ( )

} // end class Pilha
