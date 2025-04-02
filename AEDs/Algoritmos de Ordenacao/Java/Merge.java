public class Merge extends Geracao 
{
    public Merge ( )
    {
        super ( );
    }

    public Merge ( int tamanho )
    {
        super( tamanho );
    }

    /**
     *  Algoritmo que intercala os elementos entre as posicoes left e right
     *  @param int left inicio do arranjo a ser ordenado
     *  @param int mid posicao do mid do arranjo a ser ordenado
     *  @param int right fim do arranjo a ser ordenado
     */ 
    public void intercalar ( int left, int mid, int right, Log log )
    {
        int n1, n2, i, j, k;

        //Definir tamanho dos dois subarranjos
        n1 = mid-left+1;
        n2 = right - mid;

        int[] a1 = new int[n1+1];
        int[] a2 = new int[n2+1];
        log.incrementarSubarranjos(2);

        //Inicializar primeiro subarranjo
        for( i = 0; i < n1; i++ ) {
            a1[i] = arranjo[left+i];
            log.incrementarMovimentacoes();
        }
        
        //Inicializar segundo subarranjo
        for( j = 0; j < n2; j++ ) {
            a2[j] = arranjo[mid+j+1];
            log.incrementarMovimentacoes();
        }

        //Sentinela no final dos dois arranjos
        a1[i] = a2[j] = 0x7FFFFFFF;
        log.incrementarMovimentacoes(2);

        //Intercalacao propriamente dita
        for( i = j = 0, k = left; k <= right; k++ ) {
            log.incrementarComparacoes();
            arranjo[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
            log.incrementarMovimentacoes();
        }
    } // end intercalar ( )

    /**
     * Algoritmo de ordenacao Mergesort.
     * @param int left inicio do arranjo a ser ordenado
     * @param int right fim do arranjo a ser ordenado
     */
    private void mergesort (int left, int right, Log log ) 
    {
        log.incrementarComparacoes();
        if( left < right )
        {
            int mid = (left + right) / 2;
            mergesort( left, mid, log );
            mergesort( mid + 1, right, log );
            intercalar( left, mid, right, log );
        }
    } // end mergesort ( )

    @Override
    public void sort( Log log ) 
    {
        mergesort(0, tamanho-1, log);
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Merge arranjo = new Merge( 100 );
        Log log = new Log();

        System.out.println( "\n//----- MERGE SORT -----//");

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
