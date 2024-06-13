import java.util.Scanner;

class Celula 
{
    String id;
    int    pontoCardeal;
    Celula prox;

    public Celula ( ) {
        this.id = "";
        this.pontoCardeal = 0;
        this.prox = null;
    }

    public Celula ( String id, int pontoCardeal ) {
        this.id = id;
        this.pontoCardeal = pontoCardeal;
        this.prox = null;
    }
} // end class Celula

class Fila
{
    Celula primeiro;
    Celula ultimo;

    public Fila( ) {
        primeiro = new Celula( );
        ultimo = primeiro;
    }

    public void inserir ( String id, int pontoCardeal )
    {
        ultimo.prox = new Celula( id, pontoCardeal );
        ultimo = ultimo.prox;
    }

    public void mostrar ( )
    {
        for( Celula i = primeiro.prox; i != null; i = i.prox )
        {
            System.out.println( i.id + " ");
        }
    }
} // end class Fila

public class P02Q01
{
    public static void main( String[] args ) 
    {
        Scanner scan1 = new Scanner( System.in );
        Scanner scan2 = new Scanner( System.in );

        Fila   filaNorte = new Fila( );
        Fila   filaSul   = new Fila( );
        Fila   filaLeste = new Fila( );
        Fila   filaOeste = new Fila( );
        int    P  = 0;
        String id = "";

        do 
        {
            do {
                P = scan1.nextInt( );
            } while (P < -4 && -1 < P); // end do

            id = scan2.nextLine( );
            while ( id.contains("A") ) 
            {
                switch (P) 
                {
                    case -1:
                        filaOeste.inserir(id, P);
                        break;
                    case -2:
                        filaSul.inserir(id, P);
                        break;
                    case -3:
                        filaNorte.inserir(id, P);
                        break;
                    case -4:
                        filaLeste.inserir(id, P);
                        break;
                    default:
                        break;
                } // end switch
                id = scan2.nextLine( );
            } // end while
        } while ( P != 0 ); // end do
        
        filaOeste.mostrar();
        filaNorte.mostrar();
        filaSul.mostrar();
        filaLeste.mostrar();

        scan1.close();
        scan2.close();
    } // end main ( )
} // end class