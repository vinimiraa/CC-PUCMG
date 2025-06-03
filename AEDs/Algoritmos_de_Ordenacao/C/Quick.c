#include "Geracao.h"
#include "Log.h"

void quick ( int *arranjo, int esq, int dir, Log* log ) 
{
    int i = esq, j = dir;
    int pivo = arranjo[(dir+esq)/2];
    incrementarMovimentacoes( log, 1 );
    
    incrementarComparacoes( log, 1);
    while( i <= j ) 
    {
        incrementarComparacoes( log, 1 );
        while( arranjo[i] < pivo )
        {
            incrementarComparacoes( log, 1 );
            i++;
        } // end while

        incrementarComparacoes( log, 1 );
        while( arranjo[j] > pivo ) 
        {
            incrementarComparacoes( log, 1 );
            j--;
        } // end while

        incrementarComparacoes( log, 1 );
        if( i <= j ) 
        {
            swap( arranjo + i, arranjo + j );
            incrementarMovimentacoes( log, 3 );
            i++;
            j--;
        } // end if
    } // end while

    incrementarComparacoes( log, 1 );
    if( esq < j ) {
        quick( arranjo, esq, j, log );
    } // end if

    incrementarComparacoes( log, 1 );
    if( i < dir ) {
        quick( arranjo, i, dir, log );
    } // end if
} // end quick ( )

void sort ( int* arranjo, int tamanho, Log* log ) {
    quick( arranjo, 0, tamanho-1, log );
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- QUICK SORT -----//\n");

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