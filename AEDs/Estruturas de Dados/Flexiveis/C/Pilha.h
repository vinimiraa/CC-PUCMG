#ifndef __PILHAFLEX_H__
#define __PILHAFLEX_H__

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

// ---------------------------- Struct - Pilha

typedef struct s_Pilha
{
    Celula* topo;
    int tamanho;
} Pilha;

// ---------------------------- Protótipos - Célula

Celula* new_Celula ( int elemento );

// ---------------------------- Protótipos - Pilha

Pilha* new_Pilha ( void );
void delete_Pilha ( Pilha* pilha );
void inserir_Pilha ( Pilha* pilha, int elemento );
int remover_Pilha ( Pilha* pilha );
void mostrar_Pilha ( Pilha* pilha );
bool pesquisar_Pilha ( Pilha* pilha, int valor );
int tamanho_Pilha ( Pilha* pilha );


// ---------------------------- Definições - Célula

Celula* new_Celula( int personagem )
{
    Celula* celula = (Celula*) malloc ( sizeof(Celula) );
    if( celula != NULL )
    {
        celula->elemento = personagem;
        celula->prox = NULL;
    } // end if
    return ( celula );
} // end new_Celula ( )

// ---------------------------- Definições - Pilha

Pilha* new_Pilha ( void )
{
    Pilha* pilha = (Pilha*) malloc ( sizeof(Pilha) );
    if( pilha != NULL )
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    } // end if
    return( pilha );
} // end new_Pilha ( )

void delete_Pilha( Pilha* pilha )
{
    if( pilha != NULL )
    {
        if( pilha->topo != NULL )
        {
            free( pilha->topo ); pilha->topo = NULL;
            pilha->topo = 0;
        } // end while
        free( pilha ); pilha = NULL;
    } // end if
} // end delete_Pilha ( )

void inserir_Pilha ( Pilha* pilha, int elemento )
{
    if( pilha != NULL )
    {
        Celula* temp = new_Celula( elemento );
        temp->prox = pilha->topo;
        pilha->topo = temp;
        temp = NULL;
        pilha->tamanho++;
    } // end if
} // end inserir_Pilha ( )

int remover_Pilha ( Pilha* pilha )
{
    int resp = NULO;
    if( pilha != NULL )
    {
        if( pilha->topo == NULL ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Pilha Vazia!" );
        } 
        else 
        {
            Celula* temp = pilha->topo;
            resp = temp->elemento;
            pilha->topo = temp->prox;
            temp->prox = NULL;
            free( temp );
            temp = NULL;
            pilha->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_Pilha ( )

void mostrar_Pilha ( Pilha* pilha )
{
    if( pilha != NULL )
    {
        printf( "[TOP] ->" );
        for( Celula* i = pilha->topo; i != NULL; i = i->prox )
        {
            printf( " (%d) ->", i->elemento );
        } // end for ( )
        printf( " \\\n" );
    } // end if
} // end mostrar_Pilha ( )

bool pesquisar_Pilha ( Pilha* pilha, int valor )
{
    bool resp = false;
    if( pilha != NULL )
    {
        for( Celula* i = pilha->topo->prox; i != NULL; i = i->prox )
        {
            if( i->elemento == valor ) 
            {
                resp = true;
                i = NULL;
            } // end if
        } // end for
    } // end if
    return ( resp );
} // end pesquisar_Pilha ( )

int tamanho_Pilha ( Pilha* pilha ) 
{
    int resp = NULO;
    if( pilha != NULL ) {
        resp = pilha->tamanho;
    } // end if
    return ( resp );
} // end tamanho_Pilha ( )

#endif // __PILHAFLEX_H__