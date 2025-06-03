#ifndef __GERACAO_H__
#define __GERACAO_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// ---------------------------- Struct - Geracao

typedef struct s_Geracao
{
    int* arranjo;
    int tamanho;
} Geracao;

// ---------------------------- Protótipos - Geracao

void swap ( int *i, int *j );
void preencher_crescente ( Geracao* geracao );
void preencher_decrescente ( Geracao* geracao );
void preencher_aleatorio ( Geracao* geracao, int valor );
void mostrar ( Geracao* geracao );
bool isSort ( Geracao* geracao );

// ---------------------------- Definições - Geracao

Geracao* new_Geracao ( int tamanho )
{
    Geracao* geracao = (Geracao*) malloc ( sizeof(Geracao) );
    if( geracao != NULL && tamanho > 0 )
    {
        geracao->tamanho = tamanho;
        geracao->arranjo = (int*) malloc ( geracao->tamanho * sizeof(int) );
        if( geracao->arranjo != NULL )
        {
            for( int i = 0;i < geracao->tamanho; i++ ) 
            {
                geracao->arranjo[i] = -1;
            } // end for
        } // end if
    } // end if
    return ( geracao );
} // end new_Geracao ( )

void delete_Geracao ( Geracao* geracao )
{
    if( geracao != NULL )
    {
        if( geracao->arranjo != NULL )
        {
            free( geracao->arranjo ); geracao->arranjo = NULL;
        } // end if
        free( geracao ); geracao = NULL;
    } // end if
} // end delete_Geracao ( )

void swap ( int *i, int *j )
{
    int temp = *i;
    *i = *j;
    *j = temp;
} // end swap ( )

void preencher_crescente ( Geracao* geracao )
{
    if( geracao != NULL && geracao->arranjo != NULL )
    {
        for( int i = 0; i < geracao->tamanho; i = i + 1)
        {
            geracao->arranjo[i] = i;
        } // end for
    }
} // end preencher_crescente ( )

void preencher_decrescente ( Geracao* geracao )
{
    if( geracao != NULL && geracao->arranjo != NULL )
    {
        for( int i = 0; i < geracao->tamanho; i = i + 1)
        {
            geracao->arranjo[i] = geracao->tamanho - 1 - i;
        } // end for
    }
} // end preencher_decrescente ( )

void preencher_aleatorio ( Geracao* geracao, int valor )
{
    if( geracao != NULL && geracao->arranjo != NULL )
    {
        srand( time(NULL) );
        for( int i = 0; i < geracao->tamanho; i = i + 1 ) 
        {
            geracao->arranjo[i] = rand() % (valor + 1);
        } // end for
    }
} // end preencher_aleatorio ( )

void mostrar ( Geracao* geracao )
{
    if( geracao != NULL && geracao->arranjo != NULL )
    {
        printf("[");
        for( int i = 0; i < geracao->tamanho; i = i + 1 )
        {
            printf( " (%d)", geracao->arranjo[i] );
        } // end for
        printf(" ]\n");
    } // end if
} // end mostrar ( )

bool isSort ( Geracao* geracao )
{
    bool resp = false;
    if( geracao != NULL )
    {
        resp = true;
        for( int i = 1; i < geracao->tamanho; i = i + 1)
        {
            if( geracao->arranjo[i-1] > geracao->arranjo[i] )
            {
                i = geracao->tamanho;
                resp = false;
            } // end if
        } // end for
    } // end if 
    return resp;
} // end isSort ( )

#endif