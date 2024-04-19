public class Test_LinkedList extends LinkedList
{
	public static void main( String[] args ) 
    {
		try {
			System.out.println("=== LISTA FLEXIVEL SIMPLESMENTE ENCADEADA ===");
			LinkedList lista = new LinkedList( );

			lista.insertStart(1);
			lista.insertStart(0);
			lista.insertEnd(4);
			lista.insertEnd(5);
			lista.insert(2, 2);
			lista.insert(3, 3);
			lista.insert(6, 6);
			lista.insert(-1, 0);
			lista.insertEnd(7);
			lista.insertEnd(8);

			System.out.print("Apos insercoes: ");
			lista.print();

			int x1 = lista.remove(3);
			int x2 = lista.remove(2);
			int x3 = lista.removeEnd();
			int x4 = lista.removeStart();
			int x5 = lista.remove(0);
			int x6 = lista.remove(4);
			lista.insertEnd(9);

			System.out.print( "Apos remocoes (" +x1+ ", " +x2+ ", " +x3+ ", " +x4+ ", " +x5+ ", " +x6+ "): " );
			lista.print();
		} // end try
		catch( Exception erro ) {
			System.out.println(erro.getMessage());
		} // end catch 
	} // end main ( )
} // end class

