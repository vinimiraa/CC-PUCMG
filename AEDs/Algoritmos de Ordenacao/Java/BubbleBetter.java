public class BubbleBetter extends Geracao
{
    public BubbleBetter ( )
    {
        super ( );
    }

    public BubbleBetter ( int tamanho )
    {
        super( tamanho );
    }

    /**
     *  <p>Bubble Sort é um algoritmo de ordenação simples, que percorre repetidamente
     *  a lista, compara elementos adjacentes e os troca se estiverem na ordem
     *  errada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    @Override
    public void sort ( Log log )
    {
        boolean swapped = true;
        for( int i = 0; i < tamanho-1 && swapped; i++ )
        {
            swapped = false;
            for( int j = 0; j < tamanho-i-1; j++ )
            {
                log.incrementarComparacoes();
                if( arranjo[j] > arranjo[j+1] )
                {
                    swap( j, j+1 );
                    log.incrementarMovimentacoes(3);
                    swapped = true;
                } // end if
            } // end for
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        BubbleBetter arranjo = new BubbleBetter( 100 );
        Log log = new Log( );

        System.out.println( "\n//----- BUBBLE BETTER SORT -----//");

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
} // end class

