#include "Geracao.h"
#include "Log.h"

void sort ( int* arranjo, int tamanho, Log* log )
{
    bool swapped = true;
    for( int i = 0; i < tamanho-1 && swapped; i++ )
    {
        swapped = false;
        for( int j = 0; j < tamanho-i-1; j++ )
        {
            incrementarComparacoes( log, 1 );
            if( arranjo[j] >arranjo[j+1] )
            {
                swap( &arranjo[j], &arranjo[j+1] );
                incrementarMovimentacoes( log, 3 );
                swapped = true;
            } // end if
        } // end for
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- BUBBLE BETTER SORT -----//\n");

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