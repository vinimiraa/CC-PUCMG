#include "Geracao.h"
#include "Log.h"

void insertion ( int *arranjo, int tamanho, int cor, int h, Log* log )
{
    for( int i = (h + cor); i < tamanho; i+=h ) 
    {
        int tmp = arranjo[i];
        int j = i - h;
        incrementarMovimentacoes( log, 1 );

        incrementarComparacoes( log, 2 );
        while( (j >= 0) && (arranjo[j] > tmp) ) 
        {
            arranjo[j + h] = arranjo[j];
            incrementarMovimentacoes( log, 1 );
            j = j - h;
            incrementarComparacoes( log, 2 );
        } // end while
        arranjo[j + h] = tmp;
        incrementarMovimentacoes( log, 1 );
    } // end for
} // end insertion ( )

void sort ( int* arranjo, int tamanho, Log* log )
{
    int h = 1;

    do 
    { 
        h = (h * 3) + 1;
        incrementarMovimentacoes( log, 1 ); 
        incrementarComparacoes( log, 1 );
    } while( h < tamanho );

    do 
    {
        h /= 3;
        for( int cor = 0; cor < h; cor++ ) {
            insertion( arranjo, tamanho, cor, h, log );
        } // end for
        incrementarComparacoes( log, 1 );
    } while( h != 1 );
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- SHELL SORT -----//\n");

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