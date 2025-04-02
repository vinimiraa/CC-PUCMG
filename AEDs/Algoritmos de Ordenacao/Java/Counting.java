public class Counting extends Geracao 
{
    public Counting ( )
    {
        super ( );
    }

    public Counting ( int tamanho )
    {
        super( tamanho );
    }

    public int getLargest ( ) 
    {
        int result = arranjo[0];
        for( int i = 0; i < tamanho; i++ ) 
        {
            if( result < arranjo[i] ) {
                result = arranjo[i];
            }
        }
        return ( result );	
    } // end getLargest ( )

    @Override
    public void sort( Log log  ) 
    {
        //arranjo para contar o numero de ocorrencias de cada elemento
        int[] count = new int[getLargest( ) + 1];
        int[] ordenado = new int[tamanho];
        log.incrementarSubarranjos(2);

        //Inicializar cada posicao do arranjo de contagem 
        for( int i = 0; i < count.length; count[i] = 0, i++ );
        
        //Agora, o count[i] contem o numero de elemento iguais a i
        for( int i = 0; i < tamanho; 
        count[arranjo[i]]++, log.incrementarMovimentacoes(), i++ );

        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for( int i = 1; i < count.length; 
            count[i] += count[i-1], log.incrementarMovimentacoes(), i++ );

        //Ordenando
        for( int i = tamanho-1; i >= 0; 
            ordenado[count[arranjo[i]]-1] = arranjo[i], count[arranjo[i]]--, incrementarMovimentacoes(), i-- );

        //Copiando para o arranjo original
        for( int i = 0; i < tamanho; 
            arranjo[i] = ordenado[i], incrementarMovimentacoes(), i++ );
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Counting arranjo = new Counting( 100 );
        Log log = new Log( );

        System.out.println( "\n//----- COUNTING SORT -----//");

        arranjo.preencher_decrescente();

        System.out.println("\nARRANJO PRE ORDENACAO:");
        arranjo.mostrar( );

        log.inicioTempo();
        arranjo.sort( log );
        log.fimTempo();

        System.out.println("\nARRANJO POS ORDENACAO:");
        arranjo.mostrar( );

        log.mostrar( );
    } // end main ( )    
}
