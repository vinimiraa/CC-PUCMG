public class Shell extends Geracao 
{
    public Shell ( )
    {
        super ( );
    }

    public Shell ( int tamanho )
    {
        super( tamanho );
    }

    /**
     * <p>Algoritmo de Inserção modificado para ser utilizado no ShellSort.</p>
     *  
     *  @param startIndex : posição inicial do sub-arranjo.
     *  @param gap : valor do intervalor entre sub-arranjos.
     */
    void insertion( int startIndex, int gap, Log log )
    {
        for( int i = ( gap + startIndex ); i < tamanho; i = i + gap ) 
        {
            int key = arranjo[i];
            int j = i - gap;
            log.incrementarMovimentacoes(2);

            log.incrementarComparacoes(2);
            while( ( j >= 0 ) && ( arranjo[j] > key ) ) 
            {
                arranjo[j+gap] = arranjo[j];
                log.incrementarMovimentacoes(2);
                j = j - gap;
                log.incrementarComparacoes(2);
            } // end while
            arranjo[j+gap] = key;
            log.incrementarMovimentacoes();
        } // end for
    } // insertion ( )

    /**
     *  <p>Shell Sort é uma melhoria do Insertion Sort, que compara elementos
     *  distanciados por um intervalo maior e então reduz gradualmente esse
     *  intervalo. Isso produz uma lista quase ordenada, facilitando a ordenação
     *  final.</p>
     * 
     *  <p>Complexidade: Depende do intervalo escolhido. Melhor caso é O(n*log(n)), médio e pior caso variam. </p>
     *  <p>Número de comparações e movimentações: Geralmente menor do que o Insertion Sort.                   </p> 
     */
    @Override
    public void sort( Log log ) 
    {
        int gap = 1;
        do { 
            gap = (gap * 3) + 1; 
            log.incrementarMovimentacoes();
            log.incrementarComparacoes();
        } while( gap < tamanho ); // end do while
        do 
        {
            gap = gap / 3;
            for( int startIndex = 0; startIndex < gap; startIndex = startIndex + 1 ) {
                insertion( startIndex, gap, log );
            } // end for
            log.incrementarComparacoes();
        } while( gap != 1 ); // end do while
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Shell arranjo = new Shell( 100 );
        Log log = new Log();

        System.out.println( "\n//----- SHELL SORT -----//");

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
