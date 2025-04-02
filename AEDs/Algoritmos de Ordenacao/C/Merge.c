#include "Geracao.h"
#include "Log.h"

void intercalar ( int* arranjo, int esq, int meio, int dir, Log* log )
{
    int n1 = 0; 
    int n2 = 0;
    int i = 0;
    int j = 0; 
    int k = 0;

    //Definir tamanho dos dois subarrays
    n1 = meio-esq+1;
    n2 = dir - meio;

    int* a1 = (int*) malloc((n1+1) * sizeof(int)); 
    int* a2 = (int*) malloc((n2+1) * sizeof(int));
    incrementarSubarranjos( log, 2 );

    //Inicializar primeiro subarray
    for( i = 0; i < n1; i++ ) 
    {
        a1[i] = arranjo[esq+i];
        incrementarMovimentacoes( log, 1 );
    } // end for

    //Inicializar segundo subarray
    for( j = 0; j < n2; j++ ) 
    {
        a2[j] = arranjo[meio+j+1];
        incrementarMovimentacoes( log, 1 );
    } // end for

    //Sentinela no final dos dois arrays
    a1[i] = a2[j] = 0x7FFFFFFF;
    incrementarMovimentacoes( log, 1 );

    //Intercalacao propriamente dita
    for( i = j = 0, k = esq; k <= dir; k++ )
    {
        incrementarComparacoes( log, 1 );
        arranjo[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
        incrementarMovimentacoes( log, 1 );
    } // end for
} // end intercalar ( )

void merge ( int *arranjo, int esq, int dir, Log* log ) 
{
    incrementarComparacoes( log, 1 );
    if( esq < dir )
    {
        int meio = (esq + dir) / 2;
        merge( arranjo, esq, meio, log );
        merge( arranjo, meio + 1, dir, log );
        intercalar( arranjo, esq, meio, dir, log );
    } // end if
} // end merge

void sort ( int* arranjo, int tamanho, Log* log ) {
    merge( arranjo, 0, tamanho-1, log );
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- MERGE SORT -----//\n");

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