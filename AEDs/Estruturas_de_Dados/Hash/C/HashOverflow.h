#ifndef __HASHOVERFLOW_H__
#define __HASHOVERFLOW_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------------------- Constante

const int NULO = 0xFFFFF7;

// ---------------------------- Struct - Hash

typedef struct s_Hash
{
    int* tabela;
    int tamTabela;
    int tamReserva;
    int tamTotal;
    int numReserva;
} Hash;

// ---------------------------- Protótipos - Hash

Hash* new_Hash ( int tamanho );
void delete_Hash ( Hash* hash );
int hash_Hash ( Hash* hash, int elemento );
bool pesquisar_Hash ( Hash* hash , int elemento );
bool inserir_Hash ( Hash* hash , int elemento );
int remover_Hash ( Hash* hash , int elemento );

// ---------------------------- Definições - Hash

Hash* new_Hash ( int tamTab, int tamRes )
{
    Hash* hash = (Hash*) malloc ( sizeof(Hash) );
    if ( hash != NULL && tamTab > 0 && tamRes > 0 )
    {
        hash->tamTabela = tamTab;
        hash->tamReserva = tamRes;
        hash->tamTotal = tamTab + tamRes;
        hash->tabela = (int*) malloc ( hash->tamTotal * sizeof(int) );
        if( hash->tabela != NULL )
        {
            for( int i = 0; i < hash->tamTotal; i = i + 1 ) {
                hash->tabela[i] = NULO;
            } // end for
            hash->numReserva = 0;
        } // end if
    } // end if
    return ( hash );
} // end new_Hash ( )

void delete_Hash ( Hash* hash )
{
    if ( hash != NULL )
    {
        if ( hash->tabela != NULL )
        {
            free ( hash->tabela ); hash->tabela = NULL;
        } // end if
        free ( hash ); hash = NULL;
    } // end if
} // end delete_Hash ( )

int hash_Hash ( Hash* hash, int elemento )
{
    int resp = NULO;
    if ( hash != NULL ) {
        resp = ( elemento % hash->tamTotal );
    } // end if
    return ( resp );
} // end hash_Hash ( )

bool inserir_Hash ( Hash* hash , int elemento )
{
    bool result = false;
    if ( hash != NULL )
    {
        int index = hash_Hash( hash, elemento );
        if ( hash->tabela[index] == NULO )
        {
            hash->tabela[index] = elemento;
            result = true;
        } else {
            if( hash->numReserva < hash->tamReserva )
            {
                hash->tabela[hash->tamTabela + hash->numReserva] = elemento;
                hash->numReserva++;
                result = true;
            } // end if
        } // end if
    } // end if
    return ( result );
} // end inserir_Hash ( )

bool pesquisar_Hash ( Hash* hash , int elemento )
{
    bool result = false;
    if ( hash != NULL )
    {
        int index = hash_Hash( hash, elemento );
        if ( hash->tabela[index] == elemento )
        {
            result = true;
        } else {
            for( int i = 0; i < hash->tamReserva; i++ )
            {
                if( hash->tabela[hash->tamTabela+i] == elemento )
                {
                    result = true;
                    i = hash->tamReserva;
                } // end if
            } // end for
        } // end if
    } // end if
    return ( result );
} // end pesquisar_Hash ( )

int remover_Hash ( Hash* hash , int elemento )
{
    int result = NULO;
    if ( hash != NULL )
    {
        if ( pesquisar_Hash( hash, elemento ) == false ) {
            printf( "\n%s\n", "[REMOVER] ERRO: Elemento Nao Encontrado!" );
        } 
        else 
        {
            int index = hash_Hash( hash, elemento );
            if ( hash->tabela[index] == elemento )
            {
                result = hash->tabela[index];
                hash->tabela[index] = NULO;
            } else {
                for( int i = hash->tamTabela; i < hash->tamTotal; i++ )
                {
                    if( hash->tabela[i] == elemento )
                    {
                        hash->tabela[i] = NULO;
                        result = true;
                        i = hash->tamTotal;
                    } // end if
                } // end for
            } // end if
        } // end if
    } // end if
    return ( result );
} // end remover_Hash ( )

#endif // __HASHOVERFLOW_H__