public class Selection extends Geracao
{
    public Selection ( )
    {
        super ( );
    }

    public Selection ( int tamanho )
    {
        super( tamanho );
    }

    /**
     *  <p>Selection Sort é um algoritmo de ordenação que divide a lista em duas partes:
     *  uma parte ordenada e outra não ordenada. Ele seleciona repetidamente o menor
     *  elemento da parte não ordenada e o move para o final da parte ordenada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso.             </p> 
     *  <p>Número de comparações: O(n^2). -> n^2/2 - n/2  </p>
     *  <p>Número de movimentações: O(n). -> 3(n-1)       </p>
     */
    @Override
    public void sort( Log log ) 
    {
        for( int i = 0; i < tamanho - 1; i++ ) 
        {
            int minIndex = i;
            log.incrementarMovimentacoes();
            for( int j = i + 1; j < tamanho; j++ ) 
            {
                log.incrementarMovimentacoes();
                if( arranjo[j] < arranjo[minIndex] ) {
                    minIndex = j;
                    log.incrementarMovimentacoes();
                } // end if
            } // end for
            swap( i, minIndex );
            log.incrementarMovimentacoes(3);
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Selection arranjo = new Selection( 100 );
        Log log = new Log();

        System.out.println( "\n//----- SELECTION SORT -----//");

        arranjo.preencher_aleatorio();

        System.out.println("\nARRANJO PRE ORDENACAO:");
        arranjo.mostrar( );

        log.inicioTempo();
        arranjo.sort( log );
        log.fimTempo();

        System.out.println("\nARRANJO POS ORDENACAO:");
        arranjo.mostrar( );

        log.mostrar();
    } // end main ( )
}
