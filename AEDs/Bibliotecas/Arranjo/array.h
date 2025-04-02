/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca de Arranjos em C - "arranjo.h"
 *  ----------------------------------------------------------------------------
*/

// ---------------------------------- Lista de Dependências

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------- Definições Úteis

#ifndef __arranjo_H__
#define __arranjo_H__

#define bool  int
#define false 0
#define true (!false)

// ---------------------------------- Definições de Variáveis Globais

typedef struct s_intArray
{
    int  size;
    int *data;
    int  ix  ;
} intArray;

typedef intArray* ref_intArray;

typedef struct s_doubleArray
{
    int     size;
    double *data;
    int     ix  ;
} doubleArray;

typedef doubleArray* ref_doubleArray;

typedef struct s_boolArray
{
    int   size;
    bool *data;
    int   ix  ;
} boolArray;

typedef boolArray* ref_boolArray;

// ---------------------------------- Definição de Funções

// ---------------------- Definições de intArray

/**
 *  Verificar se o arranjo de inteiros e seus dados existem.
 *  @return true se existem; false caso contrário.
*/
bool exist_intArray( intArray* arranjo )
{
    bool result = false;

    if( arranjo != NULL && arranjo->data != NULL )
    {
        result = true;
    }
    
    return ( result );
} // end exist_intArray ( )

/**
 *  Criar um novo arranjo de inteiros.
 *  @return novo arranjo.
*/
intArray* new_intArray( int size )
{
    intArray* arranjo = ( intArray* ) malloc( 1 * sizeof( intArray ) );

    if( arranjo != NULL )
    {
        arranjo->size = 0;
        arranjo->data = NULL;
        arranjo->ix = -1;
        if( size > 0 )
        {
            arranjo->size = size;
            arranjo->data = ( int* ) malloc( size * sizeof( int ) );
            arranjo->ix = 0; 
        } // end if
    } // end if

    return ( arranjo );
} // end new_intArray ( )

/**
 *  Inicializar um arranjo de inteiros.
*/
void init_intArray( intArray* arranjo, int init_value )
{
    if( exist_intArray( arranjo ) )
    {
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            arranjo->data[arranjo->ix] = init_value;
        } // end for
    } // end if
} // end init_intArray ( )

/**
 *  Liberar o espeço de memória de um arranjo de inteiros.
*/
void free_intArray( intArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data != NULL )
        {
            free( arranjo->data );
        } // end if
        free( arranjo );
    } // end if
} // end free_intArray ( )

/**
 *  Mostrar no terminal padrão um arranjo de inteiros.
*/
void print_intArray( intArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%2d ", arranjo->data[arranjo->ix] ); 
            } // end for
            printf( "\n" );
        } // end if
    } // end if
} // end print_intArray ( )

/**
 *  Ler os dados e criar um arranjo de inteiros.
 *  @return arranjo com os dados lidos.
*/
intArray* read_intArray( void )
{
    intArray* arranjo = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    arranjo = new_intArray( size );

    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            arranjo->size = 0;
            arranjo->ix = 0;
        }
        else
        {
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%2d: ", arranjo->ix );
                scanf( "%d", &arranjo->data[arranjo->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( arranjo );
} // end read_intArray ( )

/**
 *  Gravar em um arquivo um arranjo de inteiros.
*/
void fprint_intArray( char* filename, intArray* arranjo )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_intArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: the arranjo does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", arranjo->size );
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            fprintf( file, "%d\n", arranjo->data[arranjo->ix] ); 
        } // end for
    } // end if

    fclose( file );
} // end fprint_intArray ( )

/**
 *  Ler de um arquivo um arranjo de inteiros.
 *  @return arranjo com os valores lidos do arquivo.
*/
intArray* fread_intArray( char* filename )
{
    FILE* file = fopen( filename, "rt" );
    intArray* arranjo = NULL;
    int n = 0;

    if( file == NULL )
    {
        printf( "\n%s\n", "[ERRO]: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &n ); fgetc( file );
        if( n < 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." ); 
        }
        else
        {
            arranjo = new_intArray( n );

            if( arranjo != NULL & arranjo->data == NULL )
            {
                arranjo->size = 0;
                arranjo->ix = 0;
            }
            else
            {
                if( arranjo != NULL )
                {
                    arranjo->ix = 0;
                    while( !feof( file ) && arranjo->ix < arranjo->size )
                    {
                        fscanf( file, "%d", &arranjo->data[arranjo->ix] );
                        fgetc( file );
                        arranjo->ix = arranjo->ix + 1;
                    } // end while
                    arranjo->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( arranjo );
} // end fread_intArray ( )

/**
 *  Inserir um valor inteiro em ums posição específica do arranjo de inteiros.
*/
void set_int_intArray( intArray* arranjo, int index, int value )
{
    if( exist_intArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size )
        {
            arranjo->data[index] = value;
        } // end if
    } // end if
} // end set_int_intArray ( )

/**
 *  Acssar um valor inteiro em uma posição específica de um arranjo de inteiros.
 *  @return valor na posição.
*/
int get_int_intArray( intArray* arranjo, int index )
{
    int value = 0;

    if( exist_intArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size ) 
        {
            value = arranjo->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_int_intArray ( )

/**
 *  Copiar um arranjo de inteiros para outro arranjo de inteiros.
 *  @return cópia do arranjo.
*/
intArray* copy_intArray( intArray* arranjo )
{
    intArray* copy = NULL;
    
    if( !exist_intArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( arranjo->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_intArray( arranjo->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = arranjo->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_intArray ( )

/**
 *  Ordenar o arranjo de inteiros em ordem crescente.
*/
void sort_up_intArray( intArray* arranjo )
{
    int y = 0;
    int x = 0;
    int aux = 0;
    if( exist_intArray( arranjo ) )
    {
        for( y = 1; y < arranjo->size; y = y + 1 )
        {
            for( x = 1; x < arranjo->size; x = x + 1 )
            {
                if( arranjo->data[x-1] > arranjo->data[x] )
                {
                    aux = arranjo->data[x-1];
                    arranjo->data[x] = arranjo->data[x-1];
                    arranjo->data[x-1] = aux;
                } // end if
            } // end for
        } // end for
    } // end if
} // end sort_up_intArray ( )

// ---------------------- Definições de doubleArray

/**
 *  Verificar se o arranjo real e seus dados existem.
 *  @return true se existem; false caso contrário.
*/
bool exist_doubleArray( doubleArray* arranjo )
{
    bool result = false;

    if( arranjo != NULL && arranjo->data != NULL )
    {
        result = true;
    }
    
    return ( result );
} // end exist_doubleArray ( )

/**
 *  Criar um novo arranjo real.
 *  @return novo arranjo.
*/
doubleArray* new_doubleArray( int size )
{
    doubleArray* arranjo = ( doubleArray* ) malloc( 1 * sizeof( doubleArray ) );

    if( arranjo != NULL )
    {
        arranjo->size = 0;
        arranjo->data = NULL;
        arranjo->ix = -1;
        if( size > 0 )
        {
            arranjo->size = size;
            arranjo->data = ( double* ) malloc( size * sizeof( double ) );
            arranjo->ix = 0; 
        } // end if
    } // end if

    return ( arranjo );
} // end new_doubleArray ( )

/**
 *  Inicializar um arranjo real.
*/
void init_doubleArray( doubleArray* arranjo, double init_value )
{
    if( exist_doubleArray( arranjo ) )
    {
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            arranjo->data[arranjo->ix] = init_value;
        } // end for
    } // end if
} // end init_doubleArray ( )

/**
 *  Liberar um espaço de memória de um arranjo real.
*/
void free_doubleArray( doubleArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data != NULL )
        {
            free( arranjo->data );
        } // end if
        free( arranjo );
    } // end if
} // end free_doubleArray ( )

/**
 *  Mostrar no terminal padrão um arranjo real.
*/
void print_doubleArray( doubleArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%.2lf ", arranjo->data[arranjo->ix] ); 
            } // end for
            printf( "\n" );
        } // end if
    } // end if
} // end print_doubleArray ( )

/**
 *  Ler os dados e criar um arranjo real.
 *  @return arranjo com os dados lidos.
*/
doubleArray* read_doubleArray( void )
{
    doubleArray* arranjo = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    arranjo = new_doubleArray( size );

    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            arranjo->size = 0;
            arranjo->ix = 0;
        }
        else
        {
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%2d: ", arranjo->ix );
                scanf( "%lf", &arranjo->data[arranjo->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( arranjo );
} // end read_doubleArray ( )

/**
 *  Gravar em um arquivo um arranjo real.
*/
void fprint_doubleArray( char* filename, doubleArray* arranjo )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_doubleArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: the arranjo does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", arranjo->size );
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            fprintf( file, "%lf\n", arranjo->data[arranjo->ix] ); 
        } // end for
    } // end if

    fclose( file );
} // end fprint_doubleArray ( )

/**
 *  Ler de um arquivo um arranjo real.
 *  @return arranjo com os valores lidos do arquivo.
*/
doubleArray* fread_doubleArray( char* filename )
{
    FILE* file = fopen( filename, "rt" );
    doubleArray* arranjo = NULL;
    int n = 0;

    if( file == NULL )
    {
        printf( "\n%s\n", "[ERRO]: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &n ); fgetc( file );
        if( n < 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." ); 
        }
        else
        {
            arranjo = new_doubleArray( n );

            if( arranjo != NULL & arranjo->data == NULL )
            {
                arranjo->size = 0;
                arranjo->ix = 0;
            }
            else
            {
                if( arranjo != NULL )
                {
                    arranjo->ix = 0;
                    while( !feof( file ) && arranjo->ix < arranjo->size )
                    {
                        fscanf( file, "%lf", &arranjo->data[arranjo->ix] );
                        fgetc( file );
                        arranjo->ix = arranjo->ix + 1;
                    } // end while
                    arranjo->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( arranjo );
} // end fread_doubleArray ( )

/**
 *  Inserir um valor real em uma posição específica de um arranjo real.
*/
void set_double_doubleArray( doubleArray* arranjo, int index, double value )
{
    if( exist_doubleArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size )
        {
            arranjo->data[index] = value;
        } // end if
    } // end if
} // end set_double_doubleArray ( )

/**
 *  Acessar um valor real em uma posição específica de um arranjo real.
 *  @return valor na posição.
*/
double get_double_doubleArray( doubleArray* arranjo, int index )
{
    double value = 0.0;

    if( exist_doubleArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size ) 
        {
            value = arranjo->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_double_doubleArray ( )

/**
 *  Copiar um arranjo real para outro arranjo real.
 *  @return cópia do arranjo.
*/
doubleArray* copy_doubleArray( doubleArray* arranjo )
{
    doubleArray* copy = NULL;
    
    if( !exist_doubleArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( arranjo->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_doubleArray( arranjo->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = arranjo->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_doubleArray ( )

/**
 *  Ordenar o arranjo real em ordem crescente.
*/
void sort_up_doubleArray( doubleArray* arranjo )
{
    int y = 0;
    int x = 0;
    double aux = 0;
    if( exist_doubleArray( arranjo ) )
    {
        for( y = 1; y < arranjo->size; y = y + 1 )
        {
            for( x = 1; x < arranjo->size; x = x + 1 )
            {
                if( arranjo->data[x-1] > arranjo->data[x] )
                {
                    aux = arranjo->data[x-1];
                    arranjo->data[x] = arranjo->data[x-1];
                    arranjo->data[x-1] = aux;
                } // end if
            } // end for
        } // end for
    } // end if
} // end sort_up_doubleArray ( )

// ---------------------- Definições de boolArray

/**
 *  Verificar se o arranjo booleano e seus dados existem.
 *  @return true se existem; false caso contrário.
*/
bool exist_boolArray( boolArray* arranjo )
{
    bool result = false;

    if( arranjo != NULL && arranjo->data != NULL )
    {
        result = true;
    }
    
    return ( result );
} // end exist_boolArray ( )

/**
 *  Criar um novo arranjo booleano.
 *  @return novo arranjo.
*/
boolArray* new_boolArray( int size )
{
    boolArray* arranjo = ( boolArray* ) malloc( 1 * sizeof( boolArray ) );

    if( arranjo != NULL )
    {
        arranjo->size = 0;
        arranjo->data = NULL;
        arranjo->ix = -1;
        if( size > 0 )
        {
            arranjo->size = size;
            arranjo->data = ( bool* ) malloc( size * sizeof( bool ) );
            arranjo->ix = 0; 
        } // end if
    } // end if

    return ( arranjo );
} // end new_boolArray ( )

/**
 *  Inicializar um arranjo booleano.
*/
void init_boolArray( boolArray* arranjo, bool init_value )
{
    if( exist_boolArray( arranjo ) )
    {
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            arranjo->data[arranjo->ix] = init_value;
        } // end for
    } // end if
} // end init_boolArray ( )

/**
 *  Liberar o espeço de memória de um arranjo booleano.
*/
void free_boolArray( boolArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data != NULL )
        {
            free( arranjo->data );
        } // end if
        free( arranjo );
    } // end if
} // end free_boolArray ( )

/**
 *  Mostrar no terminal padrão um arranjo booleano.
*/
void print_boolArray( boolArray* arranjo )
{
    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%2d ", arranjo->data[arranjo->ix] ); 
            } // end for
            printf( "\n" );
        } // end if
    } // end if
} // end print_boolArray ( )

/**
 *  Ler os dados e criar um arranjo booleano.
 *  @return arranjo com os dados lidos.
*/
boolArray* read_boolArray( void )
{
    boolArray* arranjo = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    arranjo = new_boolArray( size );

    if( arranjo != NULL )
    {
        if( arranjo->data == NULL )
        {
            arranjo->size = 0;
            arranjo->ix = 0;
        }
        else
        {
            for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
            {
                printf( "%2d: ", arranjo->ix );
                scanf( "%d", &arranjo->data[arranjo->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( arranjo );
} // end read_boolArray ( )

/**
 *  Gravar em um arquivo um arranjo booleano.
*/
void fprint_boolArray( char* filename, boolArray* arranjo )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_boolArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: the arranjo does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", arranjo->size );
        for( arranjo->ix = 0; arranjo->ix < arranjo->size; arranjo->ix = arranjo->ix + 1 )
        {
            fprintf( file, "%d\n", arranjo->data[arranjo->ix] ); 
        } // end for
    } // end if

    fclose( file );
} // end fprint_boolArray ( )

/**
 *  Ler de um arquivo um arranjo booleano.
 *  @return arranjo com os valores lidos do arquivo.
*/
boolArray* fread_boolArray( char* filename )
{
    FILE* file = fopen( filename, "rt" );
    boolArray* arranjo = NULL;
    int n = 0;

    if( file == NULL )
    {
        printf( "\n%s\n", "[ERRO]: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &n ); fgetc( file );
        if( n < 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." ); 
        }
        else
        {
            arranjo = new_boolArray( n );

            if( arranjo != NULL & arranjo->data == NULL )
            {
                arranjo->size = 0;
                arranjo->ix = 0;
            }
            else
            {
                if( arranjo != NULL )
                {
                    arranjo->ix = 0;
                    while( !feof( file ) && arranjo->ix < arranjo->size )
                    {
                        fscanf( file, "%d", &arranjo->data[arranjo->ix] );
                        fgetc( file );
                        arranjo->ix = arranjo->ix + 1;
                    } // end while
                    arranjo->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( arranjo );
} // end fread_boolArray ( )

/**
 *  Inserir um valor booleano em ums posição específica do arranjo booleano.
*/
void set_bool_boolArray( boolArray* arranjo, int index, bool value )
{
    if( exist_boolArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size )
        {
            arranjo->data[index] = value;
        } // end if
    } // end if
} // end set_bool_boolArray ( )

/**
 *  Acssar um valor booleano em uma posição específica de um arranjo booleano.
 *  @return valor na posição.
*/
int get_bool_boolArray( boolArray* arranjo, int index )
{
    bool value = 0;

    if( exist_boolArray( arranjo ) )
    {
        if( 0 <= index && index < arranjo->size ) 
        {
            value = arranjo->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_bool_boolArray ( )

/**
 *  Copiar um arranjo booleano para outro arranjo booleano.
 *  @return cópia do arranjo.
*/
boolArray* copy_boolArray( boolArray* arranjo )
{
    boolArray* copy = NULL;
    
    if( !exist_boolArray( arranjo ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( arranjo->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_boolArray( arranjo->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = arranjo->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_boolArray ( )

// ---------------------------------- Fim
#endif
