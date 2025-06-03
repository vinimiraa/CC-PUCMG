#include "Geracao.h"
#include "Log.h"

void sort ( int* arranjo, int tamanho, Log* log )
{
    for( int i = 0; i < (tamanho - 1); i++ )
    {
        int menor = i;
        incrementarMovimentacoes( log, 1 );
        for( int j = (i + 1); j < tamanho; j++ )
        {
            incrementarComparacoes( log, 1 );
            if( arranjo[menor] > arranjo[j] ) 
            {
                menor = j;
                incrementarMovimentacoes( log, 1 );
            } // end if
        } // end for
        swap( &arranjo[menor], &arranjo[i] );
        incrementarMovimentacoes( log, 3 );
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- SELECTION SORT -----//\n");

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