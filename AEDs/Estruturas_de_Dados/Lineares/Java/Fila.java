/**
 *  Fila - Primeiro a Entrar, Primeiro a Sair (FIFO)
 *  Inserção no Fim, Remoção no Início
 */
public class Fila 
{
    private int[] arranjo;
    private int tamanho;

    public Fila ( int tamanho ) 
    {
        this.arranjo = new int[tamanho];
        this.tamanho = 0;
    } // end Fila ( )

    public void inserir ( int x ) throws Exception 
    {
        if( tamanho >= arranjo.length ) {
            throw new Exception("[INSERIR] ERRO: Fila Cheia!" );
        } // end if
        arranjo[tamanho] = x;
        tamanho++;
    } // end inserir ( )

    public int remover ( ) throws Exception 
    {
        if( tamanho == 0 ) {
            throw new Exception("[REMOVER] ERRO: Fila Vazia!");
        } // end if
        int resp = arranjo[0];
        tamanho--;
        for( int i = 0; i < tamanho; i++ ) {
            arranjo[i] = arranjo[i + 1];
        } // end for
        return ( resp );
    } // end remover ( )

    public void mostrar ( ) 
    {
        System.out.print("[ [HEAD] ");
        for( int i = 0; i < tamanho; i++ ) {
            System.out.print( " " + arranjo[i] );
        } // end for
        System.out.println(" [TAIL] ]");
    } // end mostrar ( )

    public boolean pesquisar ( int x ) 
    {
        boolean retorno = false;
        for( int i = 0; i < tamanho && retorno == false; i++ ) {
            retorno = (arranjo[i] == x);
        } // end for
        return ( retorno );
    } // end pesquisar ( )

} // end class Fila
