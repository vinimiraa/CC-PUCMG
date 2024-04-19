public class TesteLista extends Lista
{
    public static void main( String[] args ) 
    {
        Lista array = new Lista( );   // criar vetor de inteiros com tamanho 10

        System.out.println( "\nLista apos Criacao: " );  
        array.printLista();                     // mostrar o arranjo de inteiros

        array.randValue();                      // atribiur valores aleatorios para o arranjo
        System.out.println( "\nLista com Valores Aleatorios: " );  
        array.printLista();                     // mostrar o arranjo de inteiros
        
        System.out.println( "\nValor a ser Pesquisado = 10" );
        System.out.println( "Pesquisa Sequencial: " + array.pesquisaSequencial(10) );
        
        System.out.println( "\nLista Antes da Ordenacao: " );
        array.printLista();                     // mostrar o arranjo de inteiros

        array.bubbleSortBest();                 // ordenar o arranjo

        System.out.println( "\nLista Depois da Ordenacao (BubbleSort): " );
        array.printLista();                     // mostrar o arranjo de inteiros
        
        System.out.println( "\nValor a ser Pesquisado = 10" );
        System.out.println( "Pesquisa Binaria: " + array.pesquisaBinaria(10, 0, array.getSize()-1) );

        int removido1 = array.removerInicio();
        int removido2 = array.removerFim();
        System.out.println( "\nValor Removido do Inicio: " + removido1 );
        System.out.println( "Valor Removido do Fim: " + removido2 );

        System.out.println( "\nLista: " );
        array.printLista();                     // mostrar o arranjo de inteiros

        System.out.println( "\nValor a ser Inserido no Inicio = 10 " );
        System.out.println( "Valor a ser Inserido no Fim = 10 " );

        array.inserirInicio(10);          // inserir valor no inicio do arranjo
        array.inserirFim(10);
        System.out.println( "\nLista: " );
        array.printLista();                     // mostrar o arranjo de inteiros
        
    } // end main ( )
} // end class
