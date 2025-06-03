public class Insertion extends Geracao 
{
    public Insertion ( )
    {
        super ( );
    }

    public Insertion ( int tamanho )
    {
        super( tamanho );
    }

    /**
     *  <p>Insertion Sort é um algoritmo de ordenação que constrói uma lista ordenada
     *  um item por vez, movendo cada novo item para a posição correta na lista
     *  ordenada.</p> 
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    @Override
    public void sort( Log log )
    {
        for( int i = 1; i < tamanho; i = i + 1 ) 
        {
            int key = arranjo[i];
            int j = i - 1;
            log.incrementarMovimentacoes();

            log.incrementarComparacoes( 2 );
            while( ( j >= 0 ) && ( arranjo[j] > key ) ) 
            {
                arranjo[j+1] = arranjo[j]; // deslocamento
                log.incrementarMovimentacoes();
                j--;
            } // end while
            arranjo[j+1] = key;
            log.incrementarMovimentacoes();
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Insertion arranjo = new Insertion( 100 );
        Log log = new Log();

        System.out.println( "\n//----- INSERTION SORT -----//");

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
