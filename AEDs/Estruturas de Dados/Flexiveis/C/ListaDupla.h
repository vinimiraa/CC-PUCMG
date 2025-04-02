#ifndef __LISTADUPLA_H__
#define __LISTADUPLA_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Célula

typedef struct s_CelulaDupla
{
    int elemento;
    struct s_CelulaDupla* ante;
    struct s_CelulaDupla* prox;
} CelulaDupla;

// ---------------------------- Struct - Lista Dupla

typedef struct s_ListaDupla
{
    CelulaDupla* primeiro;
    CelulaDupla* ultimo;
    int tamanho;
} ListaDupla;

// ---------------------------- Protótipos - Célula

CelulaDupla* new_Celula ( int elemento );

// ---------------------------- Protótipos - Lista Dupla

ListaDupla* new_ListaDupla ( void );
void delete_ListaDupla ( ListaDupla* lista );
void inserir_inicio_ListaDupla ( ListaDupla* lista, int valor );
void inserir_fim_ListaDupla ( ListaDupla* lista, int valor );
void inserir_ListaDupla ( ListaDupla* lista, int valor, int index );
int remover_inicio_ListaDupla ( ListaDupla* lista );
int remover_fim_ListaDupla ( ListaDupla* lista );
int remover_ListaDupla( ListaDupla* lista, int index );
void mostrar_ListaDupla ( ListaDupla* lista );
void mostrar_inverso_ListaDupla ( ListaDupla* lista );
int tamanho_ListaDupla ( ListaDupla* lista );

// ---------------------------- Definições - Célula

CelulaDupla* new_Celula ( int elemento )
{
    CelulaDupla* celula = (CelulaDupla*) malloc ( sizeof(CelulaDupla) );
    if( celula != NULL )
    {
        celula->elemento = elemento;
        celula->ante = celula->prox = NULL;
    } // end if
    return ( celula );
} // end new_Celula ( )

// ---------------------------- Definições - Lista Dupla

ListaDupla* new_ListaDupla ( void )
{
    ListaDupla* lista = (ListaDupla*) malloc ( sizeof(ListaDupla) );
    if( lista != NULL )
    {
        lista->ultimo = lista->primeiro = new_Celula( -1 );
        lista->tamanho = 0;
    } // end if
    return ( lista );
} // end new_ListaDupla ( )

void delete_ListaDupla ( ListaDupla* lista )
{
    if( lista != NULL )
    {
        free( lista ); lista = NULL;
    } // end if
} // end delete_ListaDupla ( )

void inserir_inicio_ListaDupla ( ListaDupla* lista, int valor )
{
    if( lista != NULL )
    {
        CelulaDupla *temp = new_Celula(-1);
        temp->prox = lista->primeiro;
        lista->primeiro->elemento = valor; 
        lista->primeiro->ante = temp;   
        lista->primeiro = temp;
        lista->tamanho++;
    } // end if
} // end inserir_inicio_ListaDupla ( )

void inserir_fim_ListaDupla ( ListaDupla* lista, int valor )
{
    if( lista != NULL )
    {
        lista->ultimo->prox = new_Celula( valor );
        lista->ultimo->prox->ante = lista->ultimo;
        lista->ultimo = lista->ultimo->prox;
        lista->tamanho++;
    } // end if
} // end inserir_fim_ListaDupla ( )

int remover_inicio_ListaDupla ( ListaDupla* lista ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER_INICIO] ERRO: Lista Dupla Vazia!" );
        }
        else 
        {
            CelulaDupla* temp = lista->primeiro;
            lista->primeiro = lista->primeiro->prox;
            resp = lista->primeiro->elemento;
            temp->prox = lista->primeiro->ante = NULL;
            free( temp );
            temp = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_inicio_ListaDupla ( )

int remover_fim_ListaDupla ( ListaDupla* lista ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER_FIM] ERRO: Lista Dupla Vazia!" );
        }
        else 
        {
            resp = lista->ultimo->elemento;
            lista->ultimo = lista->ultimo->ante;
            lista->ultimo->prox->ante = NULL;
            free( lista->ultimo->prox );
            lista->ultimo->prox = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_fim_ListaDupla ( )

void inserir_ListaDupla ( ListaDupla* lista, int valor, int index ) 
{
    if( lista != NULL )
    {
        if( index < 0 || lista->tamanho < index ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            inserir_inicio_ListaDupla( lista, valor );
        } else if( index == lista->tamanho ) {
            inserir_fim_ListaDupla( lista, valor );
        } 
        else 
        {
            CelulaDupla* i = lista->primeiro;
            for( int j = 0; j < index; j = j + 1, i = i->prox );   
            CelulaDupla* temp = new_Celula( valor );
            temp->ante = i;
            temp->prox = i->prox;
            temp->ante->prox = temp->prox->ante = temp;
            temp = i = NULL;
            lista->tamanho++;
        } // end if
    } // end if
} // end inserir_ListaDupla ( )

int remover_ListaDupla( ListaDupla* lista, int index ) 
{
    int resp = NULO;
    if( lista != NULL )
    {
        if( lista->primeiro == lista->ultimo ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Lista Dupla Vazia!" );
        } else if( index < 0 || index >= lista->tamanho  ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Posicao Invalida!" );
        } else if( index == 0 ) {
            resp = remover_inicio_ListaDupla( lista );
        } else if( index == lista->tamanho - 1 ) {
            resp = remover_fim_ListaDupla( lista );
        } 
        else 
        {
            CelulaDupla* i = lista->primeiro->prox;
            for( int j = 0; j < index; j = j + 1, i = i->prox );   
            i->ante->prox = i->prox;
            i->prox->ante = i->ante;
            resp = i->elemento;
            i->prox = i->ante = NULL;
            free( i );
            i = NULL;
            lista->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_ListaDupla ( )

void mostrar_ListaDupla ( ListaDupla* lista )
{
    if( lista != NULL )
    {
        printf( "[FIRST] ->" );
        for( CelulaDupla* i = lista->primeiro->prox; i != NULL; i = i->prox ) 
        {
            printf( " (%d) ->", i->elemento );
        } // end for
        printf( " \\\n" );
    }
} // end mostrar_ListaDupla ( )

void mostrar_inverso_ListaDupla ( ListaDupla* lista )
{
    if( lista != NULL )
    {
        printf( "[LAST] ->" );
        for( CelulaDupla* i = lista->ultimo; i != lista->primeiro; i = i->ante ) 
        {
            printf( " (%d) ->", i->elemento );
        } // end for
        printf( " \\\n" );
    }
} // end mostrar_ListaDupla ( )

bool pesquisar_ListaDupla ( ListaDupla* lista, int valor )
{
    bool resp = false;
    if( lista != NULL )
    {
        for( CelulaDupla* i = lista->primeiro->prox; i != NULL; i = i->prox )
        {
            if( i->elemento == valor ) 
            {
                resp = true;
                i = NULL;
            } // end if
        } // end for
    } // end if
    return ( resp );
} // end pesquisar_ListaDupla ( )

int tamanho_ListaDupla ( ListaDupla* lista ) 
{
    int resp = NULO;
    if( lista != NULL ) {
        resp = lista->tamanho;
    } // end if
    return ( resp );
} // end tamanho_ListaDupla ( )

#endif // __LISTADUPLA_H__
