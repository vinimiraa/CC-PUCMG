#ifndef __FILASEQ_H__
#define __FILASEQ_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Fila

/**
 *  Fila - Primeiro a Entrar, Primeiro a Sair (FIFO)
 *  Inserção no Fim, Remoção no Início
 */
typedef struct s_Fila
{
    int* arranjo;
    int tamanho;
    int MAXTAM;
} Fila;

// ---------------------------- Protótipos - Fila

Fila* new_Fila ( int MAXTAM );
void delete_Fila ( Fila* fila );
void inserir_Fila ( Fila* fila, int valor );
int remover_Fila ( Fila* fila );
void mostrar_Fila ( Fila* fila );

// ---------------------------- Definições - Fila

Fila* new_Fila ( int MAXTAM )
{
    Fila* fila = (Fila*) malloc ( sizeof(Fila) );
    if( fila != NULL && MAXTAM > 0 )
    {
        fila->MAXTAM = MAXTAM;
        fila->arranjo = (int*) malloc ( fila->MAXTAM * sizeof(int) );
        if( fila->arranjo != NULL )
        {
            for( int i = 0;i < fila->MAXTAM; i++ ) 
            {
                fila->arranjo[i] = NULO;
            } // end for
            fila->tamanho = 0;
        } // end if
    } // end if
    return ( fila );
} // end new_Fila ( )

void delete_Fila ( Fila* fila )
{
    if( fila != NULL )
    {
        if( fila->arranjo != NULL )
        {
            free( fila->arranjo ); fila->arranjo = NULL;
        } // end if
        fila->tamanho = 0;
        fila->MAXTAM = 0;
        free( fila ); fila = NULL;
    } // end if
} // end delete_Fila ( )

void inserir_Fila ( Fila* fila, int valor ) 
{
    if( fila != NULL && fila->arranjo != NULL )
    {
        if( fila->tamanho >= fila->MAXTAM ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Fila Cheia!" );
        } 
        else 
        {
            fila->arranjo[fila->tamanho] = valor;
            fila->tamanho++;
        } // end if
    } // end if
} // end inserir_Fila ( )

int remover_Fila ( Fila* fila ) 
{
    int resp = NULO;
    if( fila != NULL && fila->arranjo != NULL )
    {
        if( fila->tamanho == 0 ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Fila Vazia!" );
        } 
        else 
        {
            resp = fila->arranjo[0];
            fila->tamanho--;
            for( int i  = 0; i < fila->tamanho; i = i + 1 ) {
                fila->arranjo[i] = fila->arranjo[i+1];
            } // end for
        } // end if
    } // end if
    return ( resp );
} // end remover_Fila ( )

void mostrar_Fila ( Fila* fila )
{
    if( fila != NULL && fila->arranjo != NULL )
    {
        printf("[ [HEAD]");
        for( int i = 0; i < fila->tamanho; i = i + 1 ) {
            printf(" (%d)", fila->arranjo[i] );
        } // end for
        printf(" [TAIL] ]\n");
    } // end if
} // end mostra_Fila ( )

#endif // __FILASEQ_H__