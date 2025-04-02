public class Radix extends Geracao 
{
    public Radix ( )
    {
        super ( );
    }

    public Radix ( int tamanho )
    {
        super( tamanho );
    }

    public int getLargest ( Log log ) 
    {
        int result = arranjo[0];
        log.incrementarMovimentacoes();
        
        for( int i = 0; i < tamanho; i++ ) 
        {
            log.incrementarComparacoes();
            if( result < arranjo[i] ) {
                result = arranjo[i];
                log.incrementarMovimentacoes();
            }
        }
        return ( result );	
    } // end getLargest ( )

    public void sort ( int exp, Log log ) 
    {
        int[] count = new int[10];
        int[] output = new int[tamanho];
        log.incrementarSubarranjos(2);

        //Inicializar cada posicao do arranjo de contagem 
        for( int i = 0; i < 10; count[i] = 0, log.incrementarMovimentacoes(), i++);

        //Agora, o count[i] contem o numero de elemento iguais a i
        for( int i = 0; i < tamanho; i++ ) {
            count[(arranjo[i]/exp) % 10]++;
        }

        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for( int i = 1; i < 10; i++ ) {
            count[i] += count[i-1];
            log.incrementarMovimentacoes();
        }

        //Ordenando
        for( int i = tamanho-1; i >= 0; i-- ) {
            output[count[(arranjo[i]/exp) % 10] - 1] = arranjo[i];
            count[(arranjo[i]/exp) % 10]--;
            log.incrementarMovimentacoes();
        }

        //Copiando para o arranjo original
        for( int i = 0; i < tamanho; i++ ) {
            arranjo[i] = output[i];
            log.incrementarMovimentacoes();
        }
    } // end sort ( )

    @Override
    public void sort ( Log log ) 
    {
        int max = getLargest( log );
        log.incrementarMovimentacoes();
        
        for( int exp = 1; max/exp > 0; exp *= 10 ) {
            sort( exp, log );
        }
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Radix arranjo = new Radix( 100 );
        Log log = new Log();

        System.out.println( "\n//----- RADIX SORT -----//");

        arranjo.preencher_decrescente();

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
