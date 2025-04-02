#include "Geracao.h"
#include "Log.h"

void sort ( int* arranjo, int tamanho, Log* log )
{
    for( int i = 1; i < tamanho; i = i + 1 ) 
    {
        int tmp = arranjo[i];
        int j = i - 1;
        incrementarMovimentacoes( log, 1 );
        
        incrementarComparacoes( log, 2 );
        while( (j >= 0) && (arranjo[j] > tmp) ) 
        {
            arranjo[j + 1] = arranjo[j];
            incrementarMovimentacoes( log, 1 );
            j--;
        } // end while
        arranjo[j+1] = tmp;
        incrementarMovimentacoes( log, 1 );
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- INSERTION SORT -----//\n");

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