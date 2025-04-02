#include "Geracao.h"
#include "Log.h"

int getMaior ( int* arranjo, int tamanho, Log* log ) 
{
    int maior = arranjo[0];
    for( int i = 0; i < tamanho; i = i + 1  ) 
    {
        incrementarComparacoes( log, 1 );
        if( maior < arranjo[i] ) 
        {
            maior = arranjo[i];
            incrementarMovimentacoes( log, 1 );
        } // end if
    } // end for
    return ( maior );
} // end getMaior ( )

void sort ( int* arranjo, int tamanho, Log* log )
{
    //Array para contar o numero de ocorrencias de cada elemento
    int tamCount = getMaior(arranjo, tamanho, log) + 1;

    int count[tamCount];
    int ordenado[tamanho];
    incrementarSubarranjos( log, 2 );

    //Inicializar cada posicao do arranjo de contagem 
    for( int i = 0; i < tamCount; 
        count[i] = 0, incrementarMovimentacoes(log, 1), i = i + 1 );

    //Agora, o count[i] contem o numero de elemento iguais a i
    for( int i = 0; i < tamanho; 
        count[arranjo[i]]++, i = i + 1 );

    //Agora, o count[i] contem o numero de elemento menores ou iguais a i
    for( int i = 1; i < tamCount; 
        count[i] += count[i-1], incrementarMovimentacoes(log, 1), i = i + 1 );

    //Ordenando
    for( int i = tamanho-1; i >= 0; 
        ordenado[count[arranjo[i]]-1] = arranjo[i], incrementarMovimentacoes(log, 1), count[arranjo[i]]--, i--);

    //Copiando para o arranjo original
    for( int i = 0; i < tamanho; 
        arranjo[i] = ordenado[i], incrementarMovimentacoes(log, 1), i = i + 1 );
} // end sort ( )

int main ( void )
{
    Geracao* arranjo = new_Geracao( 100 );
    Log*     log     = new_Log ( );

    printf( "\n//----- COUNTING SORT -----//\n");

    preencher_aleatorio ( arranjo, 200 );

    printf("\nARRANJO PRE ORDENACAO:\n");
    mostrar ( arranjo );

    inicioTempo ( log );
    sort ( arranjo->arranjo, arranjo->tamanho, log );
    fimTempo ( log );

    printf("\nARRANJO POS ORDENACAO:\n");
    mostrar ( arranjo );

    registrar ( log );

    delete_Log ( log );
    delete_Geracao ( arranjo );
} // end main ( )