#ifndef __FILACIRCULAR_H__
#define __FILACIRCULAR_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - FilaCircular

/**
 *  FilaCircular - Primeiro a Entrar, Primeiro a Sair (FIFO)
 */
typedef struct s_FilaCircular
{
    int* arranjo;
    int tamanho;
    int MAXTAM;
    int primeiro;
    int ultimo;
} FilaCircular;

// ---------------------------- Protótipos - FilaCircular

FilaCircular* new_FilaCircular ( int MAXTAM );
void delete_FilaCircular ( FilaCircular* fila );
void inserir_FilaCircular ( FilaCircular* fila, int valor );
int remover_FilaCircular ( FilaCircular* fila );
void mostrar_FilaCircular ( FilaCircular* fila );

// ---------------------------- Definições - FilaCircular

FilaCircular* new_FilaCircular ( int MAXTAM )
{
    FilaCircular* fila = (FilaCircular*) malloc ( sizeof(FilaCircular) );
    if( fila != NULL && MAXTAM > 0 )
    {
        fila->MAXTAM = MAXTAM+1;
        fila->arranjo = (int*) malloc ( fila->MAXTAM * sizeof(int) );
        if( fila->arranjo != NULL )
        {
            for( int i = 0;i < fila->MAXTAM; i++ ) 
            {
                fila->arranjo[i] = NULO;
            } // end for
            fila->tamanho = 0;
            fila->primeiro = fila->ultimo = 0;
        } // end if
    } // end if
    return ( fila );
} // end new_FilaCircular ( )

void delete_FilaCircular ( FilaCircular* fila )
{
    if( fila != NULL )
    {
        if( fila->arranjo != NULL )
        {
            free( fila->arranjo ); fila->arranjo = NULL;
        } // end if
        fila->tamanho = 0;
        fila->MAXTAM = 0;
        fila->primeiro = 0;
        fila->ultimo = 0;
        free( fila ); fila = NULL;
    } // end if
} // end delete_FilaCircular ( )

void inserir_FilaCircular ( FilaCircular* fila, int valor ) 
{
    if( fila != NULL && fila->arranjo != NULL )
    {
        if( (fila->ultimo + 1) % fila->MAXTAM == fila->primeiro ) {
            printf( "\n%s\n", "[INSERIR] ERRO: Fila Circular Cheia!" );
        } 
        else {
            fila->arranjo[fila->ultimo] = valor;
            fila->ultimo = (fila->ultimo + 1) % fila->MAXTAM;
            fila->tamanho++;
        } // end if
    } // end if
} // end inserir_FilaCircular ( )

int remover_FilaCircular ( FilaCircular* fila ) 
{
    int resp = NULO;
    if( fila != NULL && fila->arranjo != NULL )
    {
        if( fila->primeiro == fila->ultimo ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Fila Circular Vazia!" );
        } 
        else 
        {
            resp = fila->arranjo[fila->primeiro];
            fila->primeiro = (fila->primeiro + 1) % fila->MAXTAM;
            fila->tamanho--;
        } // end if
    } // end if
    return ( resp );
} // end remover_FilaCircular ( )

void mostrar_FilaCircular ( FilaCircular* fila )
{
    if( fila != NULL && fila->arranjo != NULL )
    {
        printf("[ [HEAD]");
        for( int i = fila->primeiro; i < fila->ultimo; i = (i + 1) % fila->MAXTAM ) {
            printf(" (%d)", fila->arranjo[i] );
        } // end for
        printf(" [TAIL] ]\n");
    } // end if
} // end mostra_FilaCircular ( )

#endif // __FILACIRCULAR_H__
