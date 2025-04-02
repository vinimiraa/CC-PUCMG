#ifndef __HASHLISTA_H__
#define __HASHLISTA_H__

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

// ---------------------------- Struct - Lista

typedef struct s_Lista
{
    Celula* primeiro;
    Celula* ultimo;
    int tamanho;
} Lista;

// ---------------------------- Struct - Hash

typedef struct s_Hash
{
    Lista** tabela;
    int tamanho;
} Hash;

// ---------------------------- Protótipos - Célula

Celula* new_Celula ( int elemento );

// ---------------------------- Protótipos - Lista

Lista* new_Lista ( void );
void delete_Lista ( Lista* lista );
void inserir_inicio_Lista ( Lista* lista, int valor );
void inserir_fim_Lista ( Lista* lista, int valor );
void inserir_Lista ( Lista* lista, int valor, int index );
int remover_inicio_Lista ( Lista* lista );
int remover_fim_Lista ( Lista* lista );
int remover_Lista( Lista* lista, int index );
void mostrar_Lista ( Lista* lista );
bool pesquisar_Lista ( Lista* lista, int valor );
int tamanho_Lista ( Lista* lista );

// ---------------------------- Protótipos - Hash

Hash* new_Hash ( int tamanho );
void delete_Hash ( Hash* hash );
int hash_Hash ( Hash* hash, int elemento );
bool pesquisar_Hash ( Hash* hash , int elemento );
bool inserir_Hash ( Hash* hash , int elemento );
int remover_Hash ( Hash* hash , int elemento );
void mostrar_Hash ( Hash* hash );

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

// ---------------------------- Definições - Lista

Lista* new_Lista ( void )
{
    Lista* lista = (Lista*) malloc ( sizeof(Lista) );
    if( lista != NULL )
    {
        lista->ultimo = lista->primeiro = new_Celula( -1 );
        lista->tamanho = 0;
    } // end if
    return ( lista );
} // end new_Lista ( )

void delete_Lista ( Lista* lista )
{
    if( lista != NULL )
    {
        free( lista ); lista = NULL;
    } // end if
} // end delete_Lista ( )

void inserir_inicio_Lista ( Lista* lista, int valor )
{
    if( lista != NULL )
    {
        Celula* temp = new_Celula( valor );
        temp->prox = lista->primeiro->prox;
        lista->primeiro->prox = temp;
        if( lista->primeiro == lista->ultimo ) {                    
            lista->ultimo = temp;
        } // end if
        temp = NULL;
        lista->tamanho++;
    } // end if
} // end inserir_inicio_Lista ( )

void inserir_fim_Lista ( Lista* lista, int valor )
{
    if( lista != NULL )
    {
        lista->ultimo->prox = new_Celula( valor );
        lista->ultimo = lista->ultimo->prox;
        lista->tamanho++;
    } // end if
} // end inserir_fim_Lista ( )

int remover_inicio_Lista ( Lista* lista ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER_INICIO] ERRO: Lista Vazia!" );
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
} // end remover_inicio_Lista ( )

int remover_fim_Lista ( Lista* lista ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER_FIM] ERRO: Lista Vazia!" );
        } 
        else 
        {
            Celula* i = NULL;
            for( i = lista->primeiro; i->prox != lista->ultimo; i = i->prox)
            resp = lista->ultimo->elemento;
            lista->ultimo = i;
            free( lista->ultimo->prox );
            i = lista->ultimo->prox = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_fim_Lista ( )

void inserir_Lista ( Lista* lista, int valor, int index ) 
{
    if( lista != NULL )
    {
        if( index < 0 || lista->tamanho < index ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            inserir_inicio_Lista( lista, valor );
        } else if( index == lista->tamanho ) {
            inserir_fim_Lista( lista, valor );
        } 
        else 
        {
            Celula* i = lista->primeiro;
            for( int j = 0; j < index; j = j + 1, i = i->prox );   
            Celula* temp = new_Celula( valor );
            temp->prox = i->prox;
            i->prox = temp;
            temp = i = NULL;
            lista->tamanho++;
        } // end if
    } // end if
} // end inserir_Lista ( )

int remover_Lista( Lista* lista, int index ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Lista Vazia!" );
        } else if( index < 0 || index >= lista->tamanho ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            resp = remover_inicio_Lista( lista );
        } else if( index == lista->tamanho - 1 ) {
            resp = remover_fim_Lista( lista );
        } 
        else 
        {
            Celula* i = lista->primeiro;
            for( int j = 0; j < index; j = j + 1, i = i->prox );
            Celula* temp = i->prox;
            resp = temp->elemento;
            i->prox = temp->prox;
            temp->prox = NULL;
            free( temp );
            i = temp = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_Lista ( )

void mostrar_Lista ( Lista* lista )
{
    printf( "[FIRST] ->" );
    for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox ) 
    {
        printf( " (%d) ->", i->elemento );
    } // end for
    printf( " \\\n" );
} // end mostrar_Lista ( )

bool pesquisar_Lista ( Lista* lista, int valor )
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
} // end pesquisar_Lista ( )

int tamanho_Lista ( Lista* lista ) 
{
    int resp = NULO;
    if( lista != NULL ) {
        resp = lista->tamanho;
    } // end if
    return ( resp );
} // end tamanho_Lista ( )

// ---------------------------- Definições - Hash

Hash* new_Hash ( int tamanho )
{
    Hash* hash = (Hash*) malloc ( sizeof(Hash) );
    if ( hash != NULL && tamanho > 0 )
    {
        hash->tamanho = tamanho;
        hash->tabela = (Lista**) malloc ( tamanho * sizeof(Lista*) );
        if( hash->tabela != NULL )
        {
            for( int i = 0; i < hash->tamanho; i = i + 1 ) {
                hash->tabela[i] = new_Lista( );
            } // end for
        } // end if
    } // end if
    return ( hash );
} // end new_Hash ( )

void delete_Hash ( Hash* hash )
{
    if ( hash != NULL )
    {
        for( int i = 0; i < hash->tamanho; i = i + 1 ) {
            delete_Lista( hash->tabela[i] );
        } // end for
        free( hash->tabela ); hash->tabela = NULL;
        free( hash ); hash = NULL;
    } // end if
} // end delete_Hash ( )

int hash_Hash ( Hash* hash, int elemento )
{
    int resp = NULO;;
    if ( hash != NULL ) {
        resp = ( elemento % hash->tamanho );
    } // end if
    return ( resp );
} // end hash_Hash ( )

bool inserir_Hash ( Hash* hash , int elemento )
{
    bool result = false;
    if ( hash != NULL )
    {
        int index = hash_Hash( hash, elemento );
        inserir_fim_Lista( hash->tabela[index], elemento );
        result = true; 
    } // end if
    return ( result );
} // end inserir_Hash ( )


bool pesquisar_Hash ( Hash* hash , int elemento )
{
    bool result = false;
    if ( hash != NULL )
    {
        int index = hash_Hash( hash, elemento );
        result = pesquisar_Lista( hash->tabela[index], elemento );
    } // end if
    return ( result );
} // end pesquisar_Hash ( )

int remover_Hash ( Hash* hash , int elemento )
{
    int resp = NULO;
    if ( hash != NULL )
    {
        if ( pesquisar_Hash( hash, elemento ) == false ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Elemento Nao Encontrado!" );
        } 
        else 
        {
            int index = hash_Hash( hash, elemento );
            resp = remover_Lista( hash->tabela[index], elemento );
        }// end if
    } // end if
    return ( resp );
} // end remover_Hash ( )

void mostrar_Hash ( Hash* hash )
{
    if ( hash != NULL )
    {
        for( int i = 0; i < hash->tamanho; i++ ) 
        {
            printf( "%2d -> ", i );
            mostrar_Lista( hash->tabela[i] );
        } // end for
    } // end if
} // end mostrar_Hash ( )

#endif // __HASHLISTA_H__
