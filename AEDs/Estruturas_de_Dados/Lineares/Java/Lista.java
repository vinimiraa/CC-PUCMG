/**
 *  Lista - Inserir em Qualquer Posicação e Remover em Qualquer Posição
 */
public class Lista 
{
    private int[] arranjo;
    private int tamanho;

    public Lista ( int tamanho ) 
    {
        this.arranjo = new int[tamanho];
        this.tamanho = 0;
    } // end Lista ( )

    public void inserir_inicio ( int x ) throws Exception 
    {
        if( tamanho >= arranjo.length ) {
            throw new Exception("[INSERIR_INICIO] ERRO: Lista Cheia!" );
        } // end if
        for( int i = tamanho; i > 0; i-- ) {
            arranjo[i] = arranjo[i - 1];
        } // end for
        arranjo[0] = x;
        tamanho++;
    } // end inserir_inicio ( )

    public void inserir_fim (int x) throws Exception 
    {
        if( tamanho >= arranjo.length ) {
            throw new Exception("[INSERIR_FIM] ERRO: Lista Cheia!" );
        } // end if
        arranjo[tamanho] = x;
        tamanho++;
    } // end inserir_fim ( )

    public void inserir ( int x, int index ) throws Exception 
    {
        if( tamanho >= arranjo.length || index < 0 || index > tamanho ) {
            throw new Exception("[INSERIR] ERRO: Lista Cheia!" );
        } // end if
        for( int i = tamanho; i > index; i-- ) {
            arranjo[i] = arranjo[i - 1];
        } // end for
        arranjo[index] = x;
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

} // end class Lista
