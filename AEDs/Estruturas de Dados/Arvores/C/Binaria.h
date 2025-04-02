#ifndef __ARVOREBINARIA_H__
#define __ARVOREBINARIA_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Struct - No

typedef struct s_No
{
    int elemento;
    struct s_No* esq;
    struct s_No* dir;
} No;

// ---------------------------- Struct - ArvoreBinaria

typedef struct s_ArvoreBinaria
{
    No* raiz;
} ArvoreBinaria;

// ---------------------------- Protótipos - No

No* new_No ( int elemento );

// ---------------------------- Protótipos - ArvoreBinaria

ArvoreBinaria* new_ArvoreBinaria ( void );
void delete_ArvoreBinaria ( ArvoreBinaria* arvore );
void delete_No ( No* i );
void inserir_ArvoreBinaria ( ArvoreBinaria* arvore, int valor );
void inserir ( No* i, int valor );
bool pesquisar_ArvoreBinaria ( ArvoreBinaria* arvore, int valor );
bool pesquisar ( No* i, int valor );
void PreOrdem_ArvoreBinaria ( ArvoreBinaria* arvore );
void PreOrdem ( ArvoreBinaria* arvore );
void EmOrdem_ArvoreBinaria ( ArvoreBinaria* arvore );
void EmOrdem ( ArvoreBinaria* arvore );
void PosOrdem_ArvoreBinaria ( ArvoreBinaria* arvore );
void PosOrdem ( ArvoreBinaria* arvore );
int remover_ArvoreBinaria ( ArvoreBinaria* arvore, int valor );
int remover ( No* i, int valor );
No* maiorEsq ( No* i, No* j );

// ---------------------------- Definições - No

No* new_No ( int elemento )
{
    No* no = (No*) malloc ( sizeof(No) );
    if( no != NULL )
    {
        no->elemento = elemento;
        no->esq = NULL;
        no->dir = NULL;
    } // end if
    return ( no );
} // end new_No ( )

// ---------------------------- Definições - ArvoreBinaria

ArvoreBinaria* new_ArvoreBinaria ( void )
{
    ArvoreBinaria* arvore = (ArvoreBinaria*) malloc ( sizeof(ArvoreBinaria) );
    if( arvore != NULL ) {
        arvore->raiz = NULL;
    } // end if
    return ( arvore );
} // end new_ArvoreBinaria ( )

void delete_ArvoreBinaria ( ArvoreBinaria* arvore )
{
    if( arvore != NULL ) {
        delete_No ( arvore->raiz );
        free ( arvore );
    } // end if
} // end delete_ArvoreBinaria ( )

void delete_No ( No* i )
{
    if( i != NULL ) {
        delete_No ( i->esq );
        delete_No ( i->dir );
        free ( i );
    } // end if
} // end delete_No ( )

void inserir_ArvoreBinaria ( ArvoreBinaria* arvore, int valor )
{
    if( arvore != NULL ) {
        arvore->raiz = inserir ( arvore->raiz, valor );
    } // end if
} // end inserir_ArvoreBinaria ( )

void inserir ( No* i, int valor )
{
    if ( i == NULL ) {
        i = new_No ( valor ); 
    } else if ( valor < i->elemento ) {
        i->esq = inserir ( i->esq, valor );
    } else if ( valor > i->elemento ) {
        i->dir = inserir ( i->dir, valor );
    } else {
        printf( "\n%s\n", "[INSERIR] ERRO: Elemento ja existe!" );
    } // end if
    return ( i );
} // end inserir ( )

bool pesquisar_ArvoreBinaria ( ArvoreBinaria* arvore, int valor )
{
    bool resp = false;
    if( arvore != NULL ) {
        resp = pesquisar ( arvore->raiz, valor );
    } // end if
    return ( resp );
} // end pesquisar_ArvoreBinaria ( )

bool pesquisar ( No* i, int valor )
{
    bool resp = false;
    if( i == NULL ) {
        resp = false;
    } else if( valor == i->elemento ) {
        resp = true;
    } else if( valor < i->elemento ) {
        resp = pesquisar ( i->esq, valor );
    } else {
        resp = pesquisar ( i->dir, valor );
    } // end if
    return ( resp );
} // end pesquisar ( )

void PreOrdem_ArvoreBinaria ( ArvoreBinaria* arvore )
{
    if( arvore != NULL ) {
        printf( "[");
        PreOrdem ( arvore->raiz );
        printf( " ]");
    } // end if
} // end PreOrdem ( )

void PreOrdem ( No* i )
{
    if( i != NULL ) {
        printf( " %d", i->elemento );
        PreOrdem ( i->esq );
        PreOrdem ( i->dir );
    } // end if
} // end PreOrdem ( )

void EmOrdem_ArvoreBinaria ( ArvoreBinaria* arvore )
{
    if( arvore != NULL ) {
        printf( "[");
        EmOrdem ( arvore->raiz );
        printf( " ]");
    } // end if
} // end EmOrdem ( )

void EmOrdem ( No* i )
{
    if( i != NULL ) {
        EmOrdem ( i->esq );
        printf( " %d", i->elemento );
        EmOrdem ( i->dir );
    } // end if
} // end EmOrdem ( )

void PosOrdem_ArvoreBinaria ( ArvoreBinaria* arvore )
{
    if( arvore != NULL ) {
        printf( "[");
        PosOrdem ( arvore->raiz );
        printf( " ]");
    } // end if
} // end PosOrdem ( )

void PosOrdem ( No* i )
{
    if( i != NULL ) {
        PosOrdem ( i->esq );
        PosOrdem ( i->dir );
        printf( " %d", i->elemento );
    } // end if
} // end PosOrdem ( )

int remover_ArvoreBinaria ( ArvoreBinaria* arvore, int valor )
{
    int resp = 0xFFFFFF7;
    if( arvore != NULL ) {
        resp = remover ( arvore->raiz, valor );
    } // end if
    return ( resp );
} // end remover_ArvoreBinaria ( )

int remover ( No* i, int valor )
{
    int resp = 0xFFFFFF7;
    if( i == NULL ) {
        printf( "\n%s\n", "[REMOVER] ERRO: Elemento nao existe!" );
    } else if( valor < i->elemento ) {
        i->esq = remover ( i->esq, valor );
    } else if( valor > i->elemento ) {
        i->dir = remover ( i->dir, valor );
    } else if( i->dir == NULL ) {
        i = i->esq;
    } else if( i->esq == NULL ) {
        i = i->dir;
    } else {
        i->esq = maiorEsq ( i, i->esq );
    } // end if
    return ( resp );
} // end remover ( )

No* maiorEsq ( No* i, No* j )
{
    if( j == NULL ) {
        i->elemento = j->elemento;
        j = j->esq;
    } else {
        j->dir = maiorEsq ( i, j->dir );
    } // end if
    return ( j );
} // end maiorEsq ( )

#endif // __ARVOREBINARIA_H__