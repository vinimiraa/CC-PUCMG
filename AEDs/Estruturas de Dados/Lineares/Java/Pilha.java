/**
 *  Pilha - Primeiro a Entrar, Ultimo a Sair (FILO)
 *  Inserção no Fim, Remoção no Fim
 */
public class Pilha 
{
    private int[] arranjo;
    private int tamanho;

    public Pilha ( int tamanho ) 
    {
        this.arranjo = new int[tamanho];
        this.tamanho = 0;
    } // end Pilha ( )

    public void inserir ( int x ) throws Exception 
    {
        if( tamanho >= arranjo.length ) {
            throw new Exception("[INSERIR] ERRO: Pilha Cheia!" );
        } // end if
        arranjo[tamanho] = x;
        tamanho++;
    } // end inserir ( )

    public int remover ( ) throws Exception 
    {
        if( tamanho == 0 ) {
            throw new Exception("[REMOVER] ERRO: Pilha Cheia!");
        } // end if
        return ( arranjo[--tamanho] );
    } // end remover ( )

    public void mostrar ( ) 
    {
        System.out.print("[ [BOTTOM]");
        for( int i = 0; i < tamanho; i++ ) {
            System.out.print(" " + arranjo[i] );
        } // end for
        System.out.println(" [TOP] ]");
    } // end mostrar ( )

    public boolean pesquisar ( int x ) 
    {
        boolean retorno = false;
        for( int i = 0; i < tamanho && retorno == false; i++ ) {
            retorno = (arranjo[i] == x);
        } // end for
        return ( retorno );
    } // end pesquisar ( )

} // end class Pilha
