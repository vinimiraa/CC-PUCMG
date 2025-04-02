public class Log 
{
    private int comparacoes;
    private int movimentacoes;
    private int subarranjos;
    private long fimTempo;
    private long inicioTempo;
    private double totalTempo;

    public Log ( ) {
        this.comparacoes = 0;
        this.movimentacoes = 0;
        this.subarranjos = 0;
    } // end Log ( )

    public void incrementarComparacoes ( ) {
        this.comparacoes++;
    } // end incrementarComparacoes ( )

    public void incrementarComparacoes ( int amount ) {
        this.comparacoes += amount;
    } // end incrementarComparacoes ( )

    public void incrementarMovimentacoes ( ) {
        this.movimentacoes++;
    } // end incrementarMovimentacoes ( )

    public void incrementarMovimentacoes ( int amount ) {
        this.movimentacoes += amount;
    } // end incrementarMovimentacoes ( )

    public void incrementarSubarranjos ( ) {
        this.subarranjos++;
    } // end incrementarSubarranjos ( )

    public void incrementarSubarranjos ( int amout ) {
        this.subarranjos += amout;
    } // end incrementarSubarranjos ( )

    public void inicioTempo ( )
    {
        this.inicioTempo = System.nanoTime( );
    } // end inicioTempo ( )

    public void fimTempo ( )
    {
        this.fimTempo = System.nanoTime( );
    } // end fimTempo ( )

    private double calcularTempo ( )
    {
        long totalTempo = this.fimTempo - this.inicioTempo;
        this.totalTempo = totalTempo / 1_000_000.0;
        return ( this.totalTempo );
    } // end calcularTempo ( )

    public void reset ( ) 
    {
        this.comparacoes   = 0;
        this.movimentacoes = 0;
        this.subarranjos   = 0;
    } // end reset ( )

    public void mostrar ( ) 
    {
        System.out.println( "\n//----- ANALISE DO ALGORITMO -----//\n");
        System.out.println( "Tempo de Execucao             : " + calcularTempo( ) + " ms"  );
        System.out.println( "Numero de comparacoes         : " + this.comparacoes   );
        System.out.println( "Numero de movimentacoes       : " + this.movimentacoes );
        System.out.println( "Numero de subarranjos criados : " + this.subarranjos   );
        System.out.println( "\n//---------- FIM ANALISE ---------//\n");
    } // end mostrar ( )
} // end class Log
