public class Bubble extends Geracao 
{
    public Bubble ( ) {
        super ( );
    } // Bubble ( )

    public Bubble ( int tamanho ) {
        super( tamanho );
    } // Bubble ( )

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
    public void sort( Log log )
    {
        for( int i = 1; i < tamanho; i++ )
        {
            for( int j = 1; j < tamanho; j++ )
            {
                log.incrementarComparacoes();
                if( arranjo[j-1] > arranjo[j] )
                {
                    swap( j, j-1 );
                    log.incrementarMovimentacoes(3);
                } // end if
            } // end for
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {   
        Bubble arranjo = new Bubble( 100 );
        Log    log     = new Log( );

        System.out.println( "\n//----- BUBBLE SORT -----//");

        arranjo.preencher_aleatorio();

        System.out.println("\nARRANJO PRE ORDENACAO:");
        arranjo.mostrar( );

        log.inicioTempo( );
        arranjo.sort( log );
        log.fimTempo( );

        System.out.println("\nARRANJO POS ORDENACAO:");
        arranjo.mostrar( );

        log.mostrar( );
    } // end main ( )
} // end class
