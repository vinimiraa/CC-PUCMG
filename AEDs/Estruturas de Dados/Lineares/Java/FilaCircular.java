public class FilaCircular 
{
    private int[] arranjo;
    private int primeiro; // Remove do indice "primeiro".
    private int ultimo; // Insere no indice "ultimo".

    public FilaCircular ( int tamanho ) 
    {
        arranjo = new int[tamanho + 1];
        primeiro = ultimo = 0;
    } // end FilaCircular ( )

    public void inserir ( int valor ) throws Exception 
    {
        if( ((ultimo + 1) % arranjo.length) == primeiro ) {
            throw new Exception("[INSERIR] ERRO: Fila Cheia!" );
        } // end if
        arranjo[ultimo] = valor;
        ultimo = (ultimo + 1) % arranjo.length;
    } // end inserir ( )

    public int remover( ) throws Exception 
    {
        if( primeiro == ultimo ) {
            throw new Exception("[REMOVER] ERRO: Fila Vazia!");
        } // end if
        int resp = arranjo[primeiro];
        primeiro = (primeiro + 1) % arranjo.length;
        return ( resp );
    } // end remover ( )

    public void mostrar ( ) 
    {
        System.out.print("[ [HEAD]");
        for( int i = primeiro; i != ultimo; i = ((i + 1) % arranjo.length) ) {
            System.out.print( " " + arranjo[i] );
        } // end for
        System.out.println(" [TAIL] ]");
    } // end mostrar ( )

    public void mostrar_rec ( ) 
    {
        System.out.print("[ ");
        mostrarRec(primeiro);
        System.out.println("]");
    } // end mostrarRec ( )

    private void mostrarRec( int i ) 
    {
        if( i != ultimo ) 
        {
            System.out.print(arranjo[i] + " ");
            mostrarRec((i + 1) % arranjo.length);
        } // end if
    } // end mostrarRec ( )

} // end class FilaCircular
