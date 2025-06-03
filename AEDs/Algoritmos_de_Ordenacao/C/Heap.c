#include "Geracao.h"
#include "Log.h"

void construir ( int *arranjo, int tamanho, Log* log )
{
    for( int i = tamanho; i > 1 && arranjo[i] > arranjo[i/2]; i /= 2 ) 
    {
        swap( arranjo + i, arranjo + i/2 );
        incrementarMovimentacoes( log, 3 );
        incrementarComparacoes( log, 1 );
    } // end for
} // end construir ( )

int getMaiorFilho ( int *arranjo, int i, int tamanho, Log* log )
{
    int filho = 0;
    int filhoEsq = 2*i;
    int filhoDir = 2*i+1;
    incrementarComparacoes( log, 1 );
    if( filhoEsq == tamanho || arranjo[filhoEsq] > arranjo[filhoDir] ) {
        filho = filhoEsq;
    } else {
        filho = filhoDir;
    } // end if
    return ( filho );
} // end getMaiorFilho

void reconstruir ( int *arranjo, int tamanho, Log* log )
{
    int i = 1;
    while( i <= (tamanho/2) )
    {
        int filho = getMaiorFilho( arranjo, i, tamanho, log );
        incrementarComparacoes( log, 1 );
        if( arranjo[i] < arranjo[filho] )
        {
            swap( arranjo + i, arranjo + filho );
            incrementarMovimentacoes( log, 3 );
            i = filho;
        } else {
            i = tamanho;
        } // end if
    } // end while
} // end reconstruir ( )

void sort ( int* arranjo, int tamanho, Log* log )
{
    //Alterar o vetor ignorando a posicao zero
    int arrayTmp[tamanho+1];
    incrementarSubarranjos( log, 1 );
    
    for( int i = 0; i < tamanho; i++ ) 
    {
        arrayTmp[i+1] = arranjo[i];
        incrementarMovimentacoes( log, 1 );
    } // end for

    //Contrucao do heap
    for( int tam = 2; tam <= tamanho; tam++ ) {
        construir( arrayTmp, tam, log );
    } // end for

    //Ordenacao propriamente dita
    int tam = tamanho;
    incrementarComparacoes( log, 1 );
    while( tam > 1 )
    {
        swap( arrayTmp + 1, arrayTmp + tam-- );
        incrementarComparacoes( log, 3 );
        reconstruir( arrayTmp, tam, log );
        incrementarComparacoes( log, 1 );
    } // end while 

    //Alterar o vetor para voltar a posicao zero
    for( int i = 0; i < tamanho; i++ ) 
    {
        arranjo[i] = arrayTmp[i+1];
        incrementarMovimentacoes( log, 1 );
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- HEAP SORT -----//\n");

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