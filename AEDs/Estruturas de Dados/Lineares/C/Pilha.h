#ifndef __PILHASEQ_H__
#define __PILHASEQ_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Pilha

/**
 *  Pilha - Primeiro a Entrar, Ultimo a Sair (FILO)
 *  Inserção no Fim, Remoção no Fim
 */
typedef struct s_Pilha
{
    int* arranjo;
    int tamanho;
    int MAXTAM;
} Pilha;

// ---------------------------- Protótipos - Pilha

Pilha* new_Pilha ( int MAXTAM );
void delete_Pilha ( Pilha* pilha );
void inserir_Pilha ( Pilha* pilha, int valor );
int remover_Pilha ( Pilha* pilha );
void mostrar_Pilha ( Pilha* pilha );

// ---------------------------- Definições - Pilha

Pilha* new_Pilha ( int MAXTAM )
{
    Pilha* pilha = (Pilha*) malloc ( sizeof(Pilha) );
    if( pilha != NULL && MAXTAM > 0 )
    {
        pilha->MAXTAM = MAXTAM;
        pilha->arranjo = (int*) malloc ( pilha->MAXTAM * sizeof(int) );
        if( pilha->arranjo != NULL )
        {
            for( int i = 0;i < pilha->MAXTAM; i++ ) 
            {
                pilha->arranjo[i] = NULO;
            } // end for
            pilha->tamanho = 0;
        } // end if
    } // end if
    return ( pilha );
} // end new_Pilha ( )

void delete_Pilha ( Pilha* pilha )
{
    if( pilha != NULL )
    {
        if( pilha->arranjo != NULL )
        {
            free( pilha->arranjo ); pilha->arranjo = NULL;
        } // end if
        pilha->tamanho = 0;
        pilha->MAXTAM = 0;
        free( pilha ); pilha = NULL;
    } // end if
} // end delete_Pilha ( )

void inserir_Pilha ( Pilha* pilha, int valor ) 
{
    if( pilha != NULL && pilha->arranjo != NULL )
    {
        if( pilha->tamanho >= pilha->MAXTAM ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Pilha Cheia!" );
        } else {
            pilha->arranjo[pilha->tamanho] = valor;
            pilha->tamanho++;
        } // end if
    } // end if
} // end inserir_Pilha ( )

int remover_Pilha ( Pilha* pilha ) 
{
    int resp = NULO;
    if( pilha != NULL && pilha->arranjo != NULL )
    {
        if( pilha->tamanho == 0 ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Pilha Vazia!" );
        } 
        else 
        {
            pilha->tamanho--;
            resp = pilha->arranjo[pilha->tamanho];
        } // end if
    } // end if
    return ( resp );
} // end remover_Pilha ( )

void mostrar_Pilha ( Pilha* pilha )
{
    if( pilha != NULL && pilha->arranjo != NULL )
    {
        printf("[ [BOTTOM]");
        for( int i = 0; i < pilha->tamanho; i = i + 1 ) {
            printf(" (%d)", pilha->arranjo[i] );
        } // end for
        printf(" [TOP] ]\n");
    } // end if
} // end mostra_Pilha ( )

#endif // __PILHASEQ_H__
