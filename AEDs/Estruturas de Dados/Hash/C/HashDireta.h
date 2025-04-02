#ifndef __HASHDIRETA_H__
#define __HASHDIRETA_H__

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
    int tamanho;
} Hash;

// ---------------------------- Protótipos - Hash

Hash* new_Hash ( int tamanho );
void delete_Hash ( Hash* hash );
int hash_Hash ( Hash* hash, int elemento );
bool pesquisar_Hash ( Hash* hash , int elemento );
bool inserir_Hash ( Hash* hash , int elemento );
int remover_Hash ( Hash* hash , int elemento );

// ---------------------------- Definições - Hash

Hash* new_Hash ( int tamanho )
{
    Hash* hash = (Hash*) malloc ( sizeof(Hash) );
    if ( hash != NULL && tamanho > 0 )
    {
        hash->tamanho = tamanho;
        hash->tabela = (int*) malloc ( tamanho * sizeof(int) );
        if( hash->tabela != NULL )
        {
            for( int i = 0; i < hash->tamanho; i = i + 1 ) {
                hash->tabela[i] = NULO;
            } // end for
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
        if ( hash->tabela[index] == NULO )
        {
            hash->tabela[index] = elemento;
            result = true;
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
        if ( hash->tabela[index] == elemento ) {
            result = true;
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
            result = hash->tabela[index];
            hash->tabela[index] = NULO;
        } // end if
    } // end if
    return ( result );
} // end remover_Hash ( )

#endif // __HASHDIRETA_H__