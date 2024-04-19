public class List
{
    // ---------------------------------------- Atributos

    protected int[] array;     // arranjo
    protected int   size;      // tamanho real

    // ---------------------------------------- Construtores

    public List( ) 
    {
        array    = null;
        size     = -1; 
    } // end List ( );

    public List( int length ) 
    {
        if( length > 0 )
        {
            this.array    = new int[length];
            this.size     = 0;
        } // end if
    } // end List ( )
    
    // ---------------------------------------- Métodos Úteis

    public void print( )
    {
        System.out.print( "[" );
        for( int x = 0; x < size; x = x + 1 )
        {
            System.out.print( " ("+array[x]+") " );
        } // end for
        System.out.println( "]" );
    } // end printLista ( )

    /**
     *  <p>Troca os elementos de posição no array, dados os índices i e j.</p>
     *  
     *  <p>Complexidade: O(1).         </p>
     *  <p>Número de comparações: 0.   </p> 
     *  <p>Número de movimentações: 3. </p>
     *  
     *  @param i : posição do primeiro valor.
     *  @param j : posição do segundo valor:
     */
    public void swap( int i, int j ) 
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } // end swap ( )

    /**
     *  <p>Algoritmo de busca sequencial.</p>
     *  
     *  <p>Itera pelo arranjo comparando cada elemento com o valor procurado até encontrar 
     *  uma correspondência ou alcançar o final do array.</p>
     *  
     *  @param value : O valor a ser procurado no arranjo.
     *  @return {@code true} se o valor for encontrado, {@code false} caso contrário.
     */
    public boolean sequentialSearch( int value ) 
    {
        boolean found = false;
        for( int i = 0; i < size && !found; i++ ) 
        {
            if( array[i] == value ) 
            {
                found = true;
            } // end if
        } // end for
        return ( found );
    } // end sequentialSearch ( )
    
    /**
     *  <p>Algoritmo de busca binária.</p>
     *  
     *  <p>Funciona em um array ordenado e divide repetidamente o intervalo de busca pela 
     *  metade até que o valor seja encontrado ou o intervalo se torne vazio.</p>
     *  
     *  @param value :  O valor a ser procurado no array.
     *  @param left : O índice esquerdo do intervalo de busca.
     *  @param right : O índice direito do intervalo de busca.
     *  @return O índice do valor encontrado, ou -1 se o valor não for encontrado.
     */
    public int binarySearch( int value, int left, int right ) 
    {
        if( left > right ) {
            return -1; // not found
        } 
        else 
        {
            int mid = (left + right) / 2;
            if( value == array[mid] ) {
                return mid;
            } else if (value > array[mid]) {
                return binarySearch( value, mid+1, right);
            } else {
                return binarySearch( value, left, mid-1 );
            } // end if
        } // end if
    } // end binarySearch ( )

    /**
     *  <p>Quick Sort é um algoritmo de ordenação eficiente que divide o array em
     *  partições, selecionando um elemento como pivô, e rearranjando os elementos
     *  de modo que os menores que o pivô fiquem à sua esquerda e os maiores à sua
     *  direita.<p>
     *  
     *  <p>Complexidade: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.            </p>
     *  <p>Número de comparações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.   </p> 
     *  <p>Número de movimentações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso. </p>
     * 
     *  @param left : primeira posição do arranjo.
     *  @param right : ultima posição do arranjo.
     */
    public void quickSort(int left, int right) 
    {
        int i = left, j = right;
        int pivot = array[(left + right) / 2];

        while( i <= j ) 
        {
            while( array[i] < pivot ) {
                i++;
            } // end while
            while( array[j] > pivot ) {
                j--;
            } // end while
            if( i <= j ) {
                swap(i, j);
                i++;
                j--;
            } // end if
        } // end while
        if (left < j) {
            quickSort(left, j);
        } // end if
        if (i < right) {
            quickSort(i, right);
        } // end if
    } // end quickSort ( )

    public void sort ( )
    {
        quickSort( 0, size-1 );
    } // end sor

    // ---------------------------------------- Métodos de Inserção e Remoção

    /**
     *  <p>Inserir no Início / Push-Front</p>
     *  <p>Insere um novo elemento no início do array.</p>
     *  @param value : O valor a ser inserido no início do array.
     */
    public void insertStart( int value ) throws Exception
    {
        if( size >= array.length ) 
        {
            throw new Exception( "ERROR: Unable to inset at start." );
        } 
        else {
            for(int x = size; x > 0; x = x - 1 ) {
                array[x] = array[x-1];
            } // end for
            array[0] = value;
            size++;
        }// end if
    } // ens insertStart ( )

    /**
     *  <p>Inserir no Fim / Push-Back</p>
     *  <p>Insere um novo elemento no final do array.</p>
     *  @param value : O valor a ser inserido no final do array.
     */
    public void insertEnd( int value ) throws Exception
    {
        if( size >= array.length ) 
        {
            throw new Exception ( "ERROR: Unable to insert at end." );
        } 
        else {
            array[size] = value;
            size++;
        } // end if
    } // end insertEnd ( )

    /**
     *  <p>Inserir / Push</p>
     *  <p>Insere um novo elemento na posição específica do array.</p>
     *  @param value : O valor a ser inserido no array.
     *  @param index : Posição de inserção.
     */
    public void insert( int value, int index ) throws Exception
    {
        if( index < 0 && size > index )
        {
            throw new Exception( "ERROR: Unable to insert at index ("+index+")." );
        }
        else
        {
            for( int i = size; i > index; i-- ) {
                array[i] = array[i-1];
            }
            array[index] = value;
            size++;
        } // end if
    } // end insert ( )

    /**
     *  <p>Remover do Início / Pop-Front</p>
     *  <p>Remove o primeiro elemento do array e retorna o valor removido.</p>
     *  @return O valor do primeiro elemento removido, ou 0 se o array estiver vazio.
     */
    public int removeStart( ) throws Exception
    {
        int value = 0;
        if( size > 0 ) 
        {
            value = array[0];
            for (int x = 1; x < size; x = x + 1) {
                array[x - 1] = array[x];
            } // end for
            size--;
        } 
        else {
            throw new Exception( "ERROR: Unable to remove from start." );
        } // end if
        return ( value );
    } // end removeStart ( )

    /**
     *  <p>Remover do Fim / Pop-Back</p>
     *  <p>Remove o último elemento do array e retorna o valor removido.</p>
     *  @return O valor do último elemento removido, ou 0 se o array estiver vazio.
     */
    public int removeEnd( ) throws Exception
    {
        int value = 0;
        if( size > 0 ) 
        {
            value = array[size - 1];
            size--;
        } 
        else {
            throw new Exception( "ERROR: Unable to remove from end." );
        } // end if
        return ( value );
    } // end removeEnd ( )

    /**
     *  <p>Remover / Pop</p>
     *  <p>Remove o elemento do array numa posição específica e retorna o valor removido.</p>
     *  @param index : Posição de Remoção.
     *  @return O valor do elemento removido, ou 0 se o array estiver vazio.
     */
    public int remove( int index ) throws Exception
    {
        int value = 0;
        if( size == 0 || ( index < 0 && size > index ) )
        {
            throw new Exception( "ERROR: Unable to remove from ("+index+")." );
        }
        else
        {
            value = array[index];
            size--;
            for( int i = index; i < size; i++ ) {
                array[i] = array[i+1];
            } // end for
        } // end if
        return ( value );
    } // end remove ( )

} // end class
