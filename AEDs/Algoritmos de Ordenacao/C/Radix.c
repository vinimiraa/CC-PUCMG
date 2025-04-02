#include "Geracao.h"
#include "Log.h"

void counting( int *arranjo, int tamanho, int exp, Log* log ) 
{
    int count[10];
    int output[tamanho];
    incrementarSubarranjos( log, 2 );

    //Inicializar cada posicao do arranjo de contagem 
    for( int i = 0; i < 10; 
        count[i] = 0, incrementarMovimentacoes( log, 1 ), i++ );

    //Agora, o count[i] contem o numero de elemento iguais a i
    for( int i = 0; i < tamanho; i++ ) {
        count[(arranjo[i]/exp) % 10]++;
    } // end for

    //Agora, o count[i] contem o numero de elemento menores ou iguais a i
    for( int i = 1; i < 10; i++ ) 
    {
        count[i] += count[i-1];
        incrementarMovimentacoes( log, 1 );
    } // end for

    //Ordenando
    for( int i = tamanho-1; i >= 0; i-- ) 
    {
        output[count[(arranjo[i]/exp) % 10] - 1] = arranjo[i];
        count[(arranjo[i]/exp) % 10]--;
        incrementarMovimentacoes( log, 1 );
    } // end for
    
    //Copiando para o arranjo original
    for( int i = 0; i < tamanho; i++ ) 
    {
        arranjo[i] = output[i];
        incrementarMovimentacoes( log, 1 );
    } // end for
} // end couting ( )

int getMax ( int *arranjo, int tamanho, Log* log ) 
{
    int maior = arranjo[0];
    incrementarMovimentacoes( log, 1 );

    for ( int i = 1; i < tamanho; i++ ) 
    {
        incrementarComparacoes( log, 1 );
        if( maior < arranjo[i] ) {
            maior = arranjo[i];
            incrementarMovimentacoes( log, 1 );
        } // end if
    } // end for
    return ( maior );
} // end getMax ( )

void sort ( int *arranjo, int tamanho, Log* log ) 
{
    //Array para contar o numero de ocorrencias de cada elemento
    int max = getMax( arranjo, tamanho, log );
    incrementarMovimentacoes( log, 1 );

    for( int exp = 1; max/exp > 0; exp *= 10 ) 
    {
        counting( arranjo, tamanho, exp, log );
    } // end for
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- RADIX SORT -----//\n");

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