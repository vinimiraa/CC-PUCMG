public class Quick extends Geracao 
{
    public Quick ( )
    {
        super ( );
    }

    public Quick ( int tamanho )
    {
        super( tamanho );
    }

    /**
     *  <p>Quick Sort é um algoritmo de ordenação eficiente que divide o arranjo em
     *  partições, selecionando um elemento como pivô, e rearranjando os elementos
     *  de modo que os menores que o pivô fiquem à sua esquerda e os maiores à sua
     *  direita.<p>
     *  
     *  <p>Complexidade: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.            </p>
     *  <p>Número de comparações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.   </p> 
     *  <p>Número de movimentações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso. </p>
     * 
     *  @param left : primeira posição do arranjo.
     *  @param right : ultima posição do arranjo.
     */
    public void quickSort ( int left, int right, Log log ) 
    {
        int i = left, j = right;
        int pivot = arranjo[(left + right)/2];
        log.incrementarMovimentacoes();

        log.incrementarComparacoes();
        while( i <= j ) 
        {
            log.incrementarComparacoes();
            while( arranjo[i] < pivot ) {
                i++;
                log.incrementarComparacoes();
            } // end while

            log.incrementarComparacoes();
            while( arranjo[j] > pivot ) {
                j--;
                log.incrementarComparacoes();
            } // end while

            log.incrementarComparacoes();
            if( i <= j ) {
                swap( i, j );
                log.incrementarMovimentacoes(3);
                i++;
                j--;
            } // end if
        } // end while

        log.incrementarComparacoes();
        if( left < j ) {
            quickSort( left, j, log );
        } // end if
        
        log.incrementarComparacoes();
        if( i < right ) {
            quickSort( i, right, log );
        } // end if
    } // end quickSort ( )

    @Override
    public void sort ( Log log )
    {
        quickSort( 0, tamanho-1, log );
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Quick arranjo = new Quick( 100 );
        Log log = new Log();

        System.out.println( "\n//----- QUICK SORT -----//");

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
