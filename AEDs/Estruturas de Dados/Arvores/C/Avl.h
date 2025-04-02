#ifndef __AVL_H__
#define __AVL_H__

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
    int nivel;
} No;

// ---------------------------- Struct - Avl

typedef struct s_Avl
{
    No* raiz;
} Avl;

// ---------------------------- Protótipos - No

No* new_No ( int valor );
int max( int a, int b );
int get_nivel_No ( No* no );
void set_nivel_No ( No* no );
int get_fator_No ( No* no );

// ---------------------------- Protótipos - Avl

Avl* new_Avl ( void );
void delete_Avl ( Avl* avl );
void delete_No ( No* i );
void inserir_Avl ( Avl* avl, int valor );
No* inserir( No* i, int valor );
No* balancear ( No* i );
No* rotacionarDir ( No* no );
No* rotacionarEsq ( No* no );
bool pesquisar_Avl ( Avl* avl, int valor );
bool pesquisar ( No* i, int valor );
void PreOrdem_Avl ( Avl* avl );
void PreOrdem ( No* i );
void EmOrdem_Avl ( Avl* avl );
void EmOrdem ( No* i );
void PosOrdem_Avl ( Avl* avl );
void PosOrdem ( No* i );
void remover_Avl ( Avl* avl, int valor );
No* remover( No* i, int valor );
No* maiorEsq ( No* i, No* j );

// ---------------------------- Definições - No

No* new_No ( int valor )
{
    No* no = (No*) malloc ( sizeof(No) );
    if( no != NULL )
    {
        no->elemento = valor;
        no->esq = NULL;
        no->dir = NULL;
        no->nivel = 1;
    } // end if
    return ( no );
} // end new_No ( )

int max( int a, int b )
{
    return ( (a > b) ? a : b );
} // end max ( )

int get_nivel_No ( No* no )
{
    return ( (no == NULL) ? 0 : no->nivel );
} // end get_nivel_No ( )

void set_nivel_No ( No* no )
{
    if( no != NULL ) {
        no->nivel = 1 + max( get_nivel_No(no->esq), get_nivel_No(no->dir) ); 
    } // end if
} // end set_nivel_No ( )

int get_fator_No ( No* no )
{
    return ( (no == NULL) ? 0 : (get_nivel_No(no->dir) - get_nivel_No(no->esq)) );
} // end get_fator_No ( )

// ---------------------------- Definições - Avl

Avl* new_Avl ( void )
{
    Avl* avl = (Avl*) malloc ( sizeof(Avl) );
    if ( avl != NULL ) {
        avl->raiz = NULL;
    } // end if
    return ( avl );
} // end new_Avl ( )

void delete_Avl ( Avl* avl )
{
    delete_No ( avl->raiz );
    free( avl ); avl = NULL;
} // end delete_AVL ( )

void delete_No ( No* i )
{
    if( i != NULL )
    {
        delete_No (i->esq);
        delete_No (i->dir);
        free( i ); i = NULL;
    } // end if
} // end deleteNoRec ( )

void inserir_Avl ( Avl* avl, int valor ) 
{   
    if( avl != NULL ) {
        avl->raiz = inserir( avl->raiz, valor );
    } // end if
} // end inserir ( )

No* inserir( No* i, int valor )
{
    if ( i == NULL ) {
        i = new_No( valor );
    } else if ( valor < i->elemento ) {
        i->esq = inserir( i->esq, valor );
    } else if ( valor > i->elemento ) {
        i->dir = inserir( i->dir, valor );
    } else {
        printf( "\n%s\n", "[INSERIR] ERRO: Nao Foi Possivel Inserir!" );
    } // end if
    return ( balancear(i) );
} // end inserir ( )

No* balancear ( No* i )
{
    if( i != NULL )
    {
        int fator = get_fator_No( i );
        if ( abs(fator) <= 1 ) {
            set_nivel_No( i );
        } 
        else if ( fator == 2 ) 
        {
            int fatorFilhoDir = get_fator_No( i->dir );
            if( fatorFilhoDir == -1 ) {
                i->dir = rotacionarDir( i->dir );
            } // end if
            i = rotacionarEsq( i );
        } 
        else if ( fator == -2 ) 
        {
            int fatorFilhoEsq = get_fator_No( i->esq );
            if( fatorFilhoEsq == 1 ) {
                i->esq = rotacionarEsq( i->esq );
            } // end if
            i = rotacionarDir( i );
        } else {
            printf( "\n%s\n" , "[BALANCEAR] ERRO: No com Fato de Balanceamento Invalido!" );
        } // end if
    } // end if
    return ( i );
} // end balancear ( )

No* rotacionarDir ( No* no )
{
    No* noEsq = no->esq;
    No* noEsqDir = noEsq->dir;
    noEsq->dir = no;
    no->esq = noEsqDir;
    set_nivel_No( no );
    set_nivel_No( noEsq );
    return ( noEsq );
} // end rotacionarDir ( )

No* rotacionarEsq ( No* no )
{
    No* noDir = no->dir;
    No* noDirEsq = noDir->esq;
    noDir->esq = no;
    no->dir = noDirEsq;
    set_nivel_No( no );
    set_nivel_No( noDir );
    return ( noDir );
} // end rotacionarEsq ( )

bool pesquisar_Avl ( Avl* avl, int valor )
{
    bool resp = false;
    if( avl != NULL ) {
        resp = pesquisar( avl->raiz, valor );
    } // end if
    return ( resp );
} // end pesquisar ( )

bool pesquisar ( No* i, int valor )
{
    bool resp = false;
    if ( i == NULL ) {
        resp = false;
    } else if ( valor == i->elemento ) {
        resp = true;
    } else if ( valor < i->elemento ) {
        resp = pesquisar( i->esq, valor );
    } else {
        resp = pesquisar( i->dir, valor );
    } // end if
    return ( resp );
} // end pesquisar ( )

void remover_Avl ( Avl* avl, int valor )
{
    if( avl != NULL ) {
        avl->raiz = remover( avl->raiz, valor );
    } // end if
} // end remover_Avl ( )

No* remover( No* i, int valor )
{
    if ( i == NULL ) {
        printf( "\n%s\n", "[REMOVER] ERRO: Nao Foi Possivel Remover!" );
    } else if ( valor < i->elemento ) {
        i->esq = remover( i->esq, valor );
    } else if ( valor > i->elemento ) {
        i->dir = remover( i->dir, valor );
    } else if ( i->dir == NULL ) {
        i = i->esq;
    } else if ( i->esq == NULL ) {
        i = i->dir;
    } else {
        i->esq = maiorEsq( i, i->esq );
    } // end if
    return ( balancear( i ) );
} // end remover ( )

No* maiorEsq ( No* i, No* j )
{
    if ( j == NULL ) 
    {
        i->elemento = j->elemento;
        j = j->esq;
    } else {
        j->dir = maiorEsq( i, j->dir );
    } // end if
    return ( j );
} // end maiorEsq ( )

void PreOrdem_Avl ( Avl* avl )
{
    if( avl != NULL )
    {
        printf( "[" );
        PreOrdem( avl->raiz );
        printf( " ]\n" );
    } // end if
} // end PreOrdem_Avl ( )

void PreOrdem ( No* i )
{
    if ( i != NULL )
    {
        printf( " %d", i->elemento );
        PreOrdem( i->esq );
        PreOrdem( i->dir );
    } // end if
} // end PreOrdem ( )

void EmOrdem_Avl ( Avl* avl )
{
    if( avl != NULL )
    {
        printf( "[" );
        EmOrdem( avl->raiz );
        printf( " ]\n" );
    } // end if
} // end EmOrdem_Avl ( )

void EmOrdem ( No* i )
{
    if ( i != NULL )
    {
        EmOrdem( i->esq );
        printf( " %d", i->elemento );
        EmOrdem( i->dir );
    } // end if
} // end EmOrdem ( )

void PosOrdem_Avl ( Avl* avl )
{
    if( avl != NULL )
    {
        printf( "[" );
        PosOrdem( avl->raiz );
        printf( " ]\n" );
    } // end if
} // end PosOrdem_Avl ( )

void PosOrdem ( No* i )
{
    if ( i != NULL )
    {
        PosOrdem( i->esq );
        PosOrdem( i->dir );
        printf( " %d", i->elemento );
    } // end if
} // end PosOrdem ( )


#endif // __AVL_H__