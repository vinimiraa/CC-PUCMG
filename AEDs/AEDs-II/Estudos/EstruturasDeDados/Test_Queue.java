public class Test_Queue extends Queue 
{
    public static void main(String[] args) throws Exception
    {
        Queue a = new Queue( 5 );
        a.inserir(1);
        a.printFila();

        a.inserir(3);
        a.printFila();

        a.inserir(5);
        a.printFila();

        a.inserir(7);
        a.printFila();

        a.inserir(9);
        a.printFila();

        // a.inserir(2);
        a.printFila();

        a.remover();
        a.printFila();

        a.remover();
        a.printFila();

        a.inserir(4);
        a.printFila();

        a.inserir(6);
        a.printFila();

        a.remover();
        a.printFila();

        a.inserir(8);
        a.printFila();

        a.printFila();
    } // end main ( )
} // end class 
