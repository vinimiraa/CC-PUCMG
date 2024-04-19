public class Queue 
{
    // ---------------------------------------- Atributos
    
    protected int[] array;
    protected int   primeiro; // remover
    protected int   ultimo;   // inserir
    
    // ---------------------------------------- Construtores
    
    Queue( )
    {
        this( 5 );
    } // end Fila ( )
    
    Queue( int length )
    {
        array = new int[length+1];
        primeiro = ultimo = 0;
    } // end Fila ( )
    
    // ---------------------------------------- Métodos Úteis

    public void print( )
    {
        int x = primeiro;
        System.out.print( "[ " );
        while( x != ultimo )
        {
            System.out.print( array[x] + " " );
            x = (x + 1) % array.length;
        } // end while
        System.out.println( "]" );
    } // end printFila ( )

    // ---------------------------------------- Métodos de Inserção e Remoção

    public void insert( int value ) throws Exception
    {
        if (((ultimo + 1) % array.length) == primeiro)
        {
            throw new Exception("Erro!");
        }
        array[ultimo] = value;
        ultimo = (ultimo + 1) % array.length;
    } // end inserir ( )

    public int remove( ) throws Exception
    {
        int value = 0;
        if( primeiro == ultimo )
        {
            throw new Exception("Erro!");
        } // end if
        value = array[primeiro];
        primeiro = (primeiro + 1) % array.length;

        return ( value );
    } // end remover ( )

} // end class 
