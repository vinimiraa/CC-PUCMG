public class Test_list extends List 
{
    public static void main( String[] args ) throws Exception
    {
        List lista1 = new List( 10 );
        List lista2 = new List( 10 );
        List lista3 = new List( 10 );

        System.out.println( "Estrutura de Dados : Lista - Vinicius Miranda de Araujo - 812839\n" );
        
        // ---------------------------------------- Lista 1
        System.out.println( "Lista 1:" );
        
        lista1.print();
        
        lista1.insertEnd(2);     lista1.print();
        lista1.insertStart(1);   lista1.print();
        lista1.insert(3, 2);     lista1.print();
        lista1.insertEnd(4);     lista1.print();
        lista1.insertEnd(5);     lista1.print();
        lista1.insertEnd(6);     lista1.print();
        lista1.insertEnd(7);     lista1.print();
        lista1.insertEnd(8);     lista1.print();
        lista1.insertEnd(9);     lista1.print();
        lista1.insertEnd(10);    lista1.print();

        System.out.println(" ");

        lista1.removeEnd();      lista1.print();
        lista1.removeStart();    lista1.print();
        lista1.remove(4);        lista1.print();
        lista1.removeEnd();      lista1.print();
        lista1.removeStart();    lista1.print();
        lista1.removeEnd();      lista1.print();
        lista1.removeStart();    lista1.print();
        lista1.removeEnd();      lista1.print();
        lista1.removeStart();    lista1.print();
        lista1.removeEnd();      lista1.print();
        System.out.println(" ");

        // ---------------------------------------- Lista 2

        System.out.println( "Lista 2:" );

        lista2.print();

        for( int x = 10; x > 0; x-- )
        {
            lista2.insertEnd(x);    lista2.print();
        }

        System.out.println(" ");

        lista2.sort();
        lista2.print();

        System.out.println(" ");

        for( int x = 10; x > 0; x-- )
        {
            lista2.removeEnd();    lista2.print();
        }
        System.out.println(" ");

        // ---------------------------------------- Lista 3

        System.out.println( "Lista 3:" );

        lista3.print();

        for( int x = 1; x <= 10; x++ )
        {
            lista3.insertStart(x);    lista3.print();
        }

        System.out.println(" ");

        lista3.sort();
        lista3.print();

        System.out.println(" ");

        for( int x = 10; x > 0; x-- )
        {
            lista3.removeStart();    lista3.print();
        }
        System.out.println(" ");
    } // main ( )
} // end class
