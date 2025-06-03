public class ListaOrdenada 
{
    private int[] arranjo;
    private int tamanho;

    public ListaOrdenada ( int tamanho ) 
    {
        this.arranjo = new int[tamanho];
        this.tamanho = 0;
    } // end Lista ( )

    public void inserir ( int x ) throws Exception 
    {
        if( tamanho >= arranjo.length ) {
            throw new Exception("[INSERIR] ERRO: Lista Cheia!");
        }       
        int pos = 0;
        for( pos = tamanho-1; pos >= 0 && arranjo[pos] > x; pos-- ) {
            arranjo[pos+1] = arranjo[pos];
        } // end for
        arranjo[pos+1] = x;
        tamanho++;
    } // end inserir ( )

    public int remover_inicio ( ) throws Exception 
    {
        if( tamanho == 0 ) {
            throw new Exception("[REMOVER_INICIO] ERRO: Lista Vazia!");
        } // end if
        int resp = arranjo[0];
        tamanho--;
        for( int i = 0; i < tamanho; i++ ) {
            arranjo[i] = arranjo[i + 1];
        } // end for
        return ( resp );
    } // end remover_inicio ( )

    public int remover_fim ( ) throws Exception 
    {
        if( tamanho == 0 ) {
            throw new Exception("[REMOVER_FIM] ERRO: Lista Vazia!");
        } // end if
        return ( arranjo[--tamanho] );
    } // end remover_fim ( )

    public int remover ( int pos ) throws Exception 
    {
        if( tamanho == 0 || pos < 0 || pos >= tamanho ) {
            throw new Exception("[REMOVER] ERRO: Lista Vazia!");
        } // end if
        int resp = arranjo[pos];
        tamanho--;
        for( int i = pos; i < tamanho; i++ ) {
            arranjo[i] = arranjo[i + 1];
        } // end for
        return ( resp );
    } // end remover ( )

    public void mostrar ( ) 
    {
        System.out.print("[");
        for( int i = 0; i < tamanho; i++ ) {
            System.out.print( " " + arranjo[i] );
        } // end for
        System.out.println(" ]");
    } // end mostrar ( )

    public boolean pesquisar ( int x ) 
    {
        boolean retorno = false;
        for( int i = 0; i < tamanho && retorno == false; i++ ) {
            retorno = (arranjo[i] == x);
        } // end for
        return ( retorno );
    } // end pesquisar ( )

} // end class ListaOrdenada
