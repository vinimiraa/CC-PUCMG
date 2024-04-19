public class LinkedList extends Cell
{
    // ---------------------------------------- Atributos

    private Cell start;
    private Cell end;

    // ---------------------------------------- Construtores
    
    LinkedList ( )
    {
        start = new Cell ( );
        end = start;
    } // end LinkedList ( )

    // ---------------------------------------- Métodos Úteis

    /**
	 *  Mostra os elementos da lista separados por espacos.
	 */
	public void print( ) 
    {
		System.out.print("[");
        for( Cell i = start.link; i != null; i = i.link ) {
            System.out.print( " ("+i.data+") " );
        } // end for
        System.out.println("]");
    } // end print ( )

    /**
     *  Procura um elemento e retorna se ele existe.
     *  @param value Elemento a pesquisar.
     *  @return <code>true</code> se o elemento existir,
     *  <code>false</code> em caso contrario.
     */
    public boolean search ( int value ) 
    {
        boolean resp = false;
        for( Cell i = start.link; i != null; i = i.link ) 
        {
            if( i.data == value )
            {
                resp = true;
                i = end;
            } // end if
        } // end for
        return ( resp );
    } // end search ( )

    /**
     *  Calcula e retorna o tamanho, em numero de elementos, da lista.
     *  @return resp int tamanho
     */
    public int length( ) 
    {
        int length = 0; 
        for( Cell i = start; i != end; i = i.link, length++ );
        return ( length );
    } // end length ( )

    // ---------------------------------------- Métodos de Inserção e Remoção

    /**
	 *  Insere um elemento na primeira posicao da lista.
     *  @param value int elemento a ser inserido.
	 */
	public void insertStart ( int value ) 
    {
		Cell temp = new Cell(value);
        temp.link = start.link;
		start.link = temp;
		if( start == end ) {                 
			end = temp;
		} // end if
        temp = null;
	} // end insertStart ( )

	/**
	 *  Insere um elemento na ultima posicao da lista.
     *  @param value int elemento a ser inserido.
	 */
	public void insertEnd ( int value ) 
    {
		end.link = new Cell( value );
		end = end.link;
	} // end insertEnd ( )

	/**
	 *  Remove um elemento da primeira posicao da lista.
     *  @return resp int elemento a ser removido.
	 *  @throws Exception Se a lista nao contiver elementos.
	 */
	public int removeStart ( ) throws Exception 
    {
		if( start == end ) {
			throw new Exception("Erro ao remover (vazia)!");
		} // end if

        Cell temp = start;
		start = start.link;
		int resp = start.data;
        temp.link = null;
        temp = null;
		return ( resp );
	} // end remmoveStart ( )

	/**
	 *  Remove um elemento da ultima posicao da lista.
     *  @return resp int elemento a ser removido.
	 *  @throws Exception Se a lista nao contiver elementos.
	 */
	public int removeEnd ( ) throws Exception 
    {
		if (start == end) {
			throw new Exception("Erro ao remover (vazia)!");
		} // end if

		// Caminhar ate a penultima celula:
        Cell i;
        for(i = start; i.link != end; i = i.link);

        int resp = end.data; 
        end = i; 
        i = end.link = null;
        
		return ( resp );
	} // end removeEnd ( )

	/**
     *  Insere um elemento em uma posicao especifica considerando que o 
     *  start elemento valido esta na posicao 0.
     *  @param x int elemento a ser inserido.
	 *  @param index int posicao da insercao.
	 *  @throws Exception Se <code>posicao</code> invalida.
	 */
    public void insert ( int value, int index ) throws Exception 
    {
        int tamanho = length( );

        if( index < 0 || index > tamanho ) {
            throw new Exception( "Erro ao inserir posicao (" + index + " / tamanho = " + tamanho + ") invalida!" );
        } else if( index == 0 ) {
            insertStart( value );
        } else if( index == tamanho ) {
            insertEnd( value );
        } else 
        {
	    	// Caminhar ate a posicao anterior a insercao
            Cell i = start;
            for(int j = 0; j < index; j++, i = i.link);
        
            Cell temp = new Cell(value);
            temp.link = i.link;
            i.link = temp;
            temp = i = null;
        } // end if
    } // end insert ( )

	/**
     *  Remove um elemento de uma posicao especifica da lista
     *  considerando que o start elemento valido esta na posicao 0.
	 *  @param index Meio da remocao.
     *  @return resp int elemento a ser removido.
	 *  @throws Exception Se <code>posicao</code> invalida.
	 */
	public int remove ( int index ) throws Exception 
    {
        int resp = -1;
        int tamanho = length( );

        if( start == end ) {
            throw new Exception("Erro ao remover (vazia)!");
        } else if( index < 0 || index >= tamanho ) {
            throw new Exception("Erro ao remover (posicao " + index + " / " + tamanho + " invalida!");
        } else if( index == 0 ) {
            resp = removeStart( );
        } else if( index == tamanho - 1 ) {
            resp = removeEnd( );
        } else 
        {
            // Caminhar ate a posicao anterior a insercao
            Cell i = start;
            for(int j = 0; j < index; j++, i = i.link);
            
            Cell temp = i.link;
            resp = temp.data;
            i.link = temp.link;
            temp.link = null;
            i = temp = null;
        } // end if

		return ( resp );
	} // end remove ( )

} // end class
