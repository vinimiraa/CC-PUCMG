#ifndef __LISTASEQ_H__
#define __LISTASEQ_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Lista

/**
 *  Lista - Inserir em Qualquer Posicação e Remover em Qualquer Posição
 */
typedef struct s_Lista
{
    int* arranjo;
    int tamanho;
    int MAXTAM;
} Lista;

// ---------------------------- Protótipos - Lista

Lista* new_Lista ( int MAXTAM );
void delete_Lista ( Lista* lista );
void inserir_inicio_Lista ( Lista* lista, int valor );
void inserir_fim_Lista ( Lista* lista, int valor );
void inserir_Lista ( Lista* lista, int valor, int index );
int remover_inicio_Lista ( Lista* lista );
int remover_fim_Lista ( Lista* lista );
int remover_Lista ( Lista* lista, int index );
void mostrar_Lista ( Lista* lista );

// ---------------------------- Definições - Lista

Lista* new_Lista ( int MAXTAM )
{
    Lista* lista = (Lista*) malloc ( sizeof(Lista) );
    if( lista != NULL && MAXTAM > 0 )
    {
        lista->MAXTAM = MAXTAM;
        lista->arranjo = (int*) malloc ( lista->MAXTAM * sizeof(int) );
        if( lista->arranjo != NULL )
        {
            for( int i = 0;i < lista->MAXTAM; i++ ) 
            {
                lista->arranjo[i] = NULO;
            } // end for
            lista->tamanho = 0;
        } // end if
    } // end if
    return ( lista );
} // end new_Lista ( )

void delete_Lista ( Lista* lista )
{
    if( lista != NULL )
    {
        if( lista->arranjo != NULL )
        {
            free( lista->arranjo ); lista->arranjo = NULL;
        } // end if
        lista->tamanho = 0;
        lista->MAXTAM = 0;
        free( lista ); lista = NULL;
    } // end if
} // end delete_Lista ( )

void inserir_inicio_Lista ( Lista* lista, int valor ) 
{
    if( lista != NULL && lista->arranjo != NULL )
    {
        if( lista->tamanho >= lista->MAXTAM ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Lista Cheia!" );
        } 
        else 
        {
            for( int i = lista->tamanho; i > 0; i = i - 1) {
                lista->arranjo[i] = lista->arranjo[i-1];
            }
            lista->arranjo[0] = valor;
            lista->tamanho++;
        } // end if
    } // end if
} // end inserir_inicio_Lista ( )

void inserir_fim_Lista ( Lista* lista, int valor ) 
{
    if( lista != NULL && lista->arranjo != NULL )
    {
        if( lista->tamanho >= lista->MAXTAM ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Lista Cheia!" );
        } 
        else 
        {
            lista->arranjo[lista->tamanho] = valor;
            lista->tamanho++;
        } // end if
    } // end if
} // end inserir_fim_Lista ( )

void inserir_Lista ( Lista* lista, int valor, int index )
{
    if( lista != NULL )
    {
        if( lista->tamanho >= lista->MAXTAM || index < 0 || lista->tamanho < index ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Lista Cheia ou Posicao Invalida!" );
        } 
        else
        {
            for( int i = lista->tamanho; i > index; i = i + 1 ) {
                lista->arranjo[i] = lista->arranjo[i-1];
            } // end for
            lista->arranjo[index] = valor;
            lista->tamanho++;
        } // end if
    } // end if
} // end inserir_Lista ( )

int remover_inicio_Lista ( Lista* lista ) 
{
    int resp = NULO;
    if( lista != NULL && lista->arranjo != NULL )
    {
        if( lista->tamanho == 0 ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Lista Vazia!" );
        } 
        else 
        {
            resp = lista->arranjo[0];
            lista->tamanho--;
            for( int i  = 0; i < lista->tamanho; i = i + 1 ) {
                lista->arranjo[i] = lista->arranjo[i+1];
            } // end for
        } // end if
    } // end if
    return ( resp );
} // end remover_inicio_Lista ( )

int remover_fim_Lista ( Lista* lista ) 
{
    int resp = NULO;
    if( lista != NULL && lista->arranjo != NULL )
    {
        if( lista->tamanho == 0 ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Lista Vazia!" );
        } 
        else 
        {
            lista->tamanho--;
            resp = lista->arranjo[lista->tamanho];
        } // end if
    } // end if
    return ( resp );
} // end remover_fim_Lista ( )

int remover_Lista ( Lista* lista, int index ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->tamanho == 0 || index < 0 || lista->tamanho <= index ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Lista Vazia!" );
        } 
        else {
            resp = lista->arranjo[index];
            lista->tamanho--;
            for( int i = index; i < lista->tamanho; i = i + 1 ) {
                lista->arranjo[i] = lista->arranjo[i+1];
            } // end for
        } // end if
    } // end if
    return ( resp );
} // end remover_Lista ( )

void mostrar_Lista ( Lista* lista )
{
    if( lista != NULL && lista->arranjo != NULL )
    {
        printf("[");
        for( int i = 0; i < lista->tamanho; i = i + 1 ) {
            printf(" (%d)", lista->arranjo[i] );
        } // end for
        printf(" ]\n");
    } // end if
} // end mostra_Lista ( )

#endif // __LISTASEQ_H__
