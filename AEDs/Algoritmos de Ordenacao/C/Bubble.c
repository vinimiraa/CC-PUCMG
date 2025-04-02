#include "Geracao.h"
#include "Log.h"

void sort ( int* arranjo, int tamanho, Log* log )
{
    for( int i = 1; i <tamanho; i++ )
    {
        for( int j = 1; j <tamanho; j++ )
        {
            incrementarComparacoes( log, 1 );
            if(arranjo[j-1] >arranjo[j] )
            {
                swap( &arranjo[j-1], &arranjo[j] );
                incrementarMovimentacoes( log, 3 );
            } // end if
        } // end for
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- BUBBLE SORT -----//\n");

    preencher_aleatorio( arranjo, 200 );

    printf("\nARRANJO PRE ORDENACAO:\n");
    mostrar( arranjo );

    inicioTempo( log );
    sort( arranjo->arranjo, arranjo->tamanho, log );
    fimTempo( log );

    printf("\nARRANJO POS ORDENACAO:\n");
    mostrar( arranjo );

    registrar ( log );

    delete_Log ( log );
    delete_Geracao( arranjo );
} // end main ( )