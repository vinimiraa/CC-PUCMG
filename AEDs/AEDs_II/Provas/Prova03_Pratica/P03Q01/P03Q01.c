#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_Pacote
{
    char package[81];
    int  number;
} Pacote;

void ordenar ( int tam, Pacote array[] ) 
{
    for( int i = 0; i < tam-1; i++ )
    {
        for( int j = 0; j < tam -1; j++ ) 
        {
            if( array[i].number < array[j].number) 
            {
                int temp = array[i].number;
                array[i].number = array[j].number;
                array[j].number = temp; 
            } // end if
        } // end for 
    } // end for
} // end ordenar ( )

void mostrar ( int tam, Pacote array[] )
{
    for( int i = 0; i < tam; i++ ) {
        if( array[i].package != NULL && strcmp(array[i].package, "0") != 0 && array[i].number > 0 ) {
            printf( "%s 00%d\n", array[i].package, array[i].number );
        } // end if
    } // end for
} // end mostrar ( )

int main ( void )
{
    bool bit = false;
    Pacote pac[30];

    // ler enquanto não for o fim da entrada de dados
    do
    {
        // ler bit
        scanf( "%d", &bit ); getchar( );
        // equanto bit == true
        int i = 0;
        while( bit == true ) 
        {
            // ler palavra
            scanf( "%s ", &pac[i].package ); 

            // verificar se palavra == 0, se for parar, senao ler numero
            if( strcmp(pac[i].package, "0") == 0) {
                bit = false;
                fflush(stdin);
            } else {
                scanf( "%d", &pac[i].number ); 
                // consumir '\n'
                getchar( ); 
            } // end if

            // incrementar variavel
            i++;
        } // end while

        // ordenar o arranjo de pacotes
        ordenar( i, pac );

        // mostrar arranjo de pacotes
        mostrar( i, pac );

    } while ( !feof(stdin) );
    
    return ( 0 );
} // end main ( )