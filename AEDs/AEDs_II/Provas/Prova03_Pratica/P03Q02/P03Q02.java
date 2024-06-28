import java.time.LocalDate;
import java.util.Scanner;


class Avistamento 
{
    LocalDate horario;
    String nome;

    public Avistamento ( LocalDate H, String N ) {
        this.horario = H;
        this.nome = N;
    }

}

public class NoivaDoTrevo 
{
    public static void main ( String[] args ) 
    {
        Scanner scan = new Scanner( System.in );
        
        int P = 0; // valor próximo da meia noite para mais e para menos
        int Q = 0; // quantidade de pessoas que relataram o avistamento
        Avistamento [] av = new Avistamento[10];

        // ler valor
        do {
            String str = scan.nextLine( );
            String [] strs = str.split(" ");
            P = Integer.parseInt( strs[0] );
            Q = Integer.parseInt( strs[1] );
        } while ( (Q < 1 && 1000 < Q) && (P < 1 && 59 < P)  );
        
        // dada a quantidade ler horario e nome
        for( int i = 0; i < Q; i++ ) 
        {
            // ler linha de dadoos
            String str = scan.nextLine( );

            // separar os dados
            String [] line = str.split(" ");

            // atribuir respectivos dados
            av[i].horario = LocalDate.parse( line[0] );
            av[i].nome = line[1];
        } // end for

        ordenar( Q, av );

        mostrar( P, Q, av );

        // fechar o scan
        scan.close( );

    } // end main ( )

    public static void ordenar ( int tam, Avistamento [] array )
    {
        for( int i = 0; i < tam-1; i++ )
        {
            for( int j = 0; j < tam-1; j++ )
            {
                if( array[i].horario.isBefore(array[j].horario) )
                {
                    Avistamento temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                } // end if
            } // end for
        } // end for
    } // end ordenar ( )

    public static void mostrar( int hora, int tam, Avistamento [] array ) 
    {
        LocalDate horario = LocalDate.parse( Integer.toString(hora) );
        for( int i = 0; i < tam; i++ )
        {
            if( !(array[i].horario.isBefore(horario) && array[i].horario.isAfter(horario)) ) 
            {
                System.out.println( array[i].nome );
            } // end if
        } // end for
    } // end mostrar ( )
    
} // end class NoivaDoTrevo