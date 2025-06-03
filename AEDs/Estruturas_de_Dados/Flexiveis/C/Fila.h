#ifndef __FILAFLEX_H__
#define __FILAFLEX_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Célula

typedef struct s_Celula
{
    int elemento;
    struct s_Celula* prox;
} Celula;

// ---------------------------- Struct - Fila

typedef struct s_Fila
{
    Celula* primeiro;
    Celula* ultimo;
    int tamanho;
} Fila;

// ---------------------------- Protótipos - Célula

Celula* new_Celula ( int elemento );

// ---------------------------- Protótipos - Fila

Fila* new_Fila ( void );
void delete_Fila ( Fila* lista );
void inserir_Fila ( Fila* lista, int valor );
int remover_Fila ( Fila* lista );
void mostrar_Fila ( Fila* lista );
bool pesquisar_Fila ( Fila* lista, int valor );
int tamanho_Fila ( Fila* lista );

// ---------------------------- Definições - Célula

Celula* new_Celula ( int elemento )
{
    Celula* celula = (Celula*) malloc ( sizeof(Celula) );
    if( celula != NULL )
    {
        celula->elemento = elemento;
        celula->prox = NULL;
    } // end if
    return ( celula );
} // end new_Celula ( )

// ---------------------------- Definições - Fila

Fila* new_Fila ( void )
{
    Fila* lista = (Fila*) malloc ( sizeof(Fila) );
    if( lista != NULL )
    {
        lista->ultimo = lista->primeiro = new_Celula( -1 );
        lista->tamanho = 0;
    } // end if
    return ( lista );
} // end new_Fila ( )

void delete_Fila ( Fila* lista )
{
    if( lista != NULL )
    {
        free( lista ); lista = NULL;
    } // end if
} // end delete_Fila ( )

void inserir_Fila ( Fila* lista, int valor )
{
    if( lista != NULL )
    {
        lista->ultimo->prox = new_Celula( valor );
        lista->ultimo = lista->ultimo->prox;
        lista->tamanho++;
    } // end if
} // end inserir_Fila ( )

int remover_Fila ( Fila* lista ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Fila Vazia!" );
        } 
        else 
        {
            Celula* temp = lista->primeiro;
            lista->primeiro = lista->primeiro->prox;
            resp = lista->primeiro->elemento;
            temp->prox = NULL;
            free( temp );
            temp = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_Fila ( )

void mostrar_Fila ( Fila* lista )
{
    printf( "[FIRST] ->" );
    for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox ) 
    {
        printf( " (%d) ->", i->elemento );
    } // end for
    printf( " \\\n" );
} // end mostrar_Fila ( )

bool pesquisar_Fila ( Fila* lista, int valor )
{
    bool resp = false;
    if( lista != NULL )
    {
        for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox )
        {
            if( i->elemento == valor ) 
            {
                resp = true;
                i = NULL;
            } // end if
        } // end for
    } // end if
    return ( resp );
} // end pesquisar_Fila ( )

int tamanho_Fila ( Fila* lista ) 
{
    int resp = NULO;
    if( lista != NULL ) {
        resp = lista->tamanho;
    } // end if
    return ( resp );
} // end tamanho_Fila ( )

#endif // __FILAFLEX_H__
