public class Heap extends Geracao 
{
    public Heap ( )
    {
        super ( );
    }

    public Heap ( int tamanho )
    {
        super( tamanho );
    }

    public void build ( int size, Log log )
    {
        for( int i = size; i > 1 && arranjo[i] > arranjo[i/2]; i /= 2 ) {
            swap( i, i/2 );
            log.incrementarMovimentacoes(3);
            incrementarComparacoes();
        }
    } // end build ( )

    public void rebuild ( int size, Log log )
    {
        int i = 1;
        while( i <= (size/2) )
        {
            int child = getLargestChild( i, size, log );
            incrementarComparacoes();
            if( arranjo[i] < arranjo[child] )
            {
                swap(i, child);
                i = child;
                incrementarMovimentacoes(4);
            }
            else {
                i = size;
            }
        }
    } // end rebuild ( )

    public int getLargestChild ( int i, int size, Log log )
    {
        int child = -1;
        int left = 2*i;
        int right = 2*i+1;
        log.incrementarComparacoes();
        if( left == size || arranjo[left] > arranjo[right] ) {
            child = left;
        } 
        else {
            child = right;
        }
        return ( child );
    } // end getLargestChild ( )

    @Override
    public void sort( Log log ) 
    {
        //Alterar o vetor ignorando a posicao zero
        int[] temp = new int[tamanho+1];
        log.incrementarSubarranjos();

        for( int i = 0; i < tamanho; i++ ) 
        {
            temp[i+1] = arranjo[i];
            log.incrementarMovimentacoes();
        }
        arranjo = temp;

        //Contrucao do heap
        for( int size = 2; size <= tamanho; size++ ) {
            build ( size, log );
        }

        //Ordenacao propriamente dita
        int size = tamanho;
        log.incrementarComparacoes();
        while( size > 1 )
        {
            swap( 1, size-- );
            log.incrementarMovimentacoes(3);
            rebuild ( size, log );
            log.incrementarComparacoes();
        } 

        //Alterar o vetor para voltar a posicao zero
        temp = arranjo;
        arranjo = new int[tamanho];
        log.incrementarMovimentacoes(2);
        for( int i = 0; i < tamanho; i++ ) {
            arranjo[i] = temp[i+1];
            log.incrementarMovimentacoes();
        }
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Heap arranjo = new Heap( 100 );
        Log log = new Log( );

        System.out.println( "\n//----- HEAP SORT -----//");

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
