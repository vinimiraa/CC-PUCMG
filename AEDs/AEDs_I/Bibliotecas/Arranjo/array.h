/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca de Arranjos em C - "array.h"
 *  ----------------------------------------------------------------------------
 *  Copyright (c) 2023, Vinicius MIranda de Araujo
 *  Todos os direitos reservados.
 *  
 *  Este código fonte é propriedade exclusiva de Vinicius Miranda de Araujo e não pode ser
 *  copiado, modificado, distribuído, ou sublicenciado por qualquer outra pessoa
 *  sem autorização expressa por escrito do autor. O uso deste código está
 *  sujeito aos termos e condições estabelecidos no contrato de licença, se fornecido,
 *  ou, na ausência de tal contrato, pelos termos padrão da Licença MIT.
 *  ----------------------------------------------------------------------------
*/

// ---------------------------------- Lista de Dependências

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------- Definições Úteis

#ifndef __ARRAY_H__
#define __ARRAY_H__

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
bool exist_intArray( intArray* array )
{
    bool result = false;

    if( array != NULL && array->data != NULL )
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
    intArray* array = ( intArray* ) malloc( 1 * sizeof( intArray ) );

    if( array != NULL )
    {
        array->size = 0;
        array->data = NULL;
        array->ix = -1;
        if( size > 0 )
        {
            array->size = size;
            array->data = ( int* ) malloc( size * sizeof( int ) );
            array->ix = 0; 
        } // end if
    } // end if

    return ( array );
} // end new_intArray ( )

/**
 *  Inicializar um arranjo de inteiros.
*/
void init_intArray( intArray* array, int init_value )
{
    if( exist_intArray( array ) )
    {
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            array->data[array->ix] = init_value;
        } // end for
    } // end if
} // end init_intArray ( )

/**
 *  Liberar o espeço de memória de um arranjo de inteiros.
*/
void free_intArray( intArray* array )
{
    if( array != NULL )
    {
        if( array->data != NULL )
        {
            free( array->data );
        } // end if
        free( array );
    } // end if
} // end free_intArray ( )

/**
 *  Mostrar no terminal padrão um arranjo de inteiros.
*/
void print_intArray( intArray* array )
{
    if( array != NULL )
    {
        if( array->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%2d ", array->data[array->ix] ); 
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
    intArray* array = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    array = new_intArray( size );

    if( array != NULL )
    {
        if( array->data == NULL )
        {
            array->size = 0;
            array->ix = 0;
        }
        else
        {
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%2d: ", array->ix );
                scanf( "%d", &array->data[array->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( array );
} // end read_intArray ( )

/**
 *  Gravar em um arquivo um arranjo de inteiros.
*/
void fprint_intArray( char* filename, intArray* array )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_intArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: the array does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", array->size );
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            fprintf( file, "%d\n", array->data[array->ix] ); 
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
    intArray* array = NULL;
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
            array = new_intArray( n );

            if( array != NULL & array->data == NULL )
            {
                array->size = 0;
                array->ix = 0;
            }
            else
            {
                if( array != NULL )
                {
                    array->ix = 0;
                    while( !feof( file ) && array->ix < array->size )
                    {
                        fscanf( file, "%d", &array->data[array->ix] );
                        fgetc( file );
                        array->ix = array->ix + 1;
                    } // end while
                    array->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( array );
} // end fread_intArray ( )

/**
 *  Inserir um valor inteiro em ums posição específica do arranjo de inteiros.
*/
void set_int_intArray( intArray* array, int index, int value )
{
    if( exist_intArray( array ) )
    {
        if( 0 <= index && index < array->size )
        {
            array->data[index] = value;
        } // end if
    } // end if
} // end set_int_intArray ( )

/**
 *  Acssar um valor inteiro em uma posição específica de um arranjo de inteiros.
 *  @return valor na posição.
*/
int get_int_intArray( intArray* array, int index )
{
    int value = 0;

    if( exist_intArray( array ) )
    {
        if( 0 <= index && index < array->size ) 
        {
            value = array->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_int_intArray ( )

/**
 *  Copiar um arranjo de inteiros para outro arranjo de inteiros.
 *  @return cópia do arranjo.
*/
intArray* copy_intArray( intArray* array )
{
    intArray* copy = NULL;
    
    if( !exist_intArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( array->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_intArray( array->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = array->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_intArray ( )

/**
 *  Ordenar o arranjo de inteiros em ordem crescente.
*/
void sort_up_intArray( intArray* array )
{
    int y = 0;
    int x = 0;
    int aux = 0;
    if( exist_intArray( array ) )
    {
        for( y = 1; y < array->size; y = y + 1 )
        {
            for( x = 1; x < array->size; x = x + 1 )
            {
                if( array->data[x-1] > array->data[x] )
                {
                    aux = array->data[x-1];
                    array->data[x] = array->data[x-1];
                    array->data[x-1] = aux;
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
bool exist_doubleArray( doubleArray* array )
{
    bool result = false;

    if( array != NULL && array->data != NULL )
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
    doubleArray* array = ( doubleArray* ) malloc( 1 * sizeof( doubleArray ) );

    if( array != NULL )
    {
        array->size = 0;
        array->data = NULL;
        array->ix = -1;
        if( size > 0 )
        {
            array->size = size;
            array->data = ( double* ) malloc( size * sizeof( double ) );
            array->ix = 0; 
        } // end if
    } // end if

    return ( array );
} // end new_doubleArray ( )

/**
 *  Inicializar um arranjo real.
*/
void init_doubleArray( doubleArray* array, double init_value )
{
    if( exist_doubleArray( array ) )
    {
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            array->data[array->ix] = init_value;
        } // end for
    } // end if
} // end init_doubleArray ( )

/**
 *  Liberar um espaço de memória de um arranjo real.
*/
void free_doubleArray( doubleArray* array )
{
    if( array != NULL )
    {
        if( array->data != NULL )
        {
            free( array->data );
        } // end if
        free( array );
    } // end if
} // end free_doubleArray ( )

/**
 *  Mostrar no terminal padrão um arranjo real.
*/
void print_doubleArray( doubleArray* array )
{
    if( array != NULL )
    {
        if( array->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%.2lf ", array->data[array->ix] ); 
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
    doubleArray* array = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    array = new_doubleArray( size );

    if( array != NULL )
    {
        if( array->data == NULL )
        {
            array->size = 0;
            array->ix = 0;
        }
        else
        {
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%2d: ", array->ix );
                scanf( "%lf", &array->data[array->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( array );
} // end read_doubleArray ( )

/**
 *  Gravar em um arquivo um arranjo real.
*/
void fprint_doubleArray( char* filename, doubleArray* array )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_doubleArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: the array does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", array->size );
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            fprintf( file, "%lf\n", array->data[array->ix] ); 
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
    doubleArray* array = NULL;
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
            array = new_doubleArray( n );

            if( array != NULL & array->data == NULL )
            {
                array->size = 0;
                array->ix = 0;
            }
            else
            {
                if( array != NULL )
                {
                    array->ix = 0;
                    while( !feof( file ) && array->ix < array->size )
                    {
                        fscanf( file, "%lf", &array->data[array->ix] );
                        fgetc( file );
                        array->ix = array->ix + 1;
                    } // end while
                    array->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( array );
} // end fread_doubleArray ( )

/**
 *  Inserir um valor real em uma posição específica de um arranjo real.
*/
void set_double_doubleArray( doubleArray* array, int index, double value )
{
    if( exist_doubleArray( array ) )
    {
        if( 0 <= index && index < array->size )
        {
            array->data[index] = value;
        } // end if
    } // end if
} // end set_double_doubleArray ( )

/**
 *  Acessar um valor real em uma posição específica de um arranjo real.
 *  @return valor na posição.
*/
double get_double_doubleArray( doubleArray* array, int index )
{
    double value = 0.0;

    if( exist_doubleArray( array ) )
    {
        if( 0 <= index && index < array->size ) 
        {
            value = array->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_double_doubleArray ( )

/**
 *  Copiar um arranjo real para outro arranjo real.
 *  @return cópia do arranjo.
*/
doubleArray* copy_doubleArray( doubleArray* array )
{
    doubleArray* copy = NULL;
    
    if( !exist_doubleArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( array->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_doubleArray( array->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = array->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_doubleArray ( )

/**
 *  Ordenar o arranjo real em ordem crescente.
*/
void sort_up_doubleArray( doubleArray* array )
{
    int y = 0;
    int x = 0;
    double aux = 0;
    if( exist_doubleArray( array ) )
    {
        for( y = 1; y < array->size; y = y + 1 )
        {
            for( x = 1; x < array->size; x = x + 1 )
            {
                if( array->data[x-1] > array->data[x] )
                {
                    aux = array->data[x-1];
                    array->data[x] = array->data[x-1];
                    array->data[x-1] = aux;
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
bool exist_boolArray( boolArray* array )
{
    bool result = false;

    if( array != NULL && array->data != NULL )
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
    boolArray* array = ( boolArray* ) malloc( 1 * sizeof( boolArray ) );

    if( array != NULL )
    {
        array->size = 0;
        array->data = NULL;
        array->ix = -1;
        if( size > 0 )
        {
            array->size = size;
            array->data = ( bool* ) malloc( size * sizeof( bool ) );
            array->ix = 0; 
        } // end if
    } // end if

    return ( array );
} // end new_boolArray ( )

/**
 *  Inicializar um arranjo booleano.
*/
void init_boolArray( boolArray* array, bool init_value )
{
    if( exist_boolArray( array ) )
    {
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            array->data[array->ix] = init_value;
        } // end for
    } // end if
} // end init_boolArray ( )

/**
 *  Liberar o espeço de memória de um arranjo booleano.
*/
void free_boolArray( boolArray* array )
{
    if( array != NULL )
    {
        if( array->data != NULL )
        {
            free( array->data );
        } // end if
        free( array );
    } // end if
} // end free_boolArray ( )

/**
 *  Mostrar no terminal padrão um arranjo booleano.
*/
void print_boolArray( boolArray* array )
{
    if( array != NULL )
    {
        if( array->data == NULL )
        {
            printf( "\n%s\n", "[ NULL ]" );
        }
        else
        {   
            printf( "\n" );
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%2d ", array->data[array->ix] ); 
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
    boolArray* array = NULL;
    int size = 0;

    do
    {
        printf( "\n%s", "Size = " );
        scanf( "%d", &size );
        getchar( );
    } while ( size <= 0 );

    array = new_boolArray( size );

    if( array != NULL )
    {
        if( array->data == NULL )
        {
            array->size = 0;
            array->ix = 0;
        }
        else
        {
            for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
            {
                printf( "%2d: ", array->ix );
                scanf( "%d", &array->data[array->ix] );
                getchar( );
            } // end for
        } // end of
    } // end if

    return ( array );
} // end read_boolArray ( )

/**
 *  Gravar em um arquivo um arranjo booleano.
*/
void fprint_boolArray( char* filename, boolArray* array )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_boolArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: the array does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", array->size );
        for( array->ix = 0; array->ix < array->size; array->ix = array->ix + 1 )
        {
            fprintf( file, "%d\n", array->data[array->ix] ); 
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
    boolArray* array = NULL;
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
            array = new_boolArray( n );

            if( array != NULL & array->data == NULL )
            {
                array->size = 0;
                array->ix = 0;
            }
            else
            {
                if( array != NULL )
                {
                    array->ix = 0;
                    while( !feof( file ) && array->ix < array->size )
                    {
                        fscanf( file, "%d", &array->data[array->ix] );
                        fgetc( file );
                        array->ix = array->ix + 1;
                    } // end while
                    array->ix = 0;
                } // end if
            } // end if
        } // end if
    } // end if

    fclose( file );
    return( array );
} // end fread_boolArray ( )

/**
 *  Inserir um valor booleano em ums posição específica do arranjo booleano.
*/
void set_bool_boolArray( boolArray* array, int index, bool value )
{
    if( exist_boolArray( array ) )
    {
        if( 0 <= index && index < array->size )
        {
            array->data[index] = value;
        } // end if
    } // end if
} // end set_bool_boolArray ( )

/**
 *  Acssar um valor booleano em uma posição específica de um arranjo booleano.
 *  @return valor na posição.
*/
int get_bool_boolArray( boolArray* array, int index )
{
    bool value = 0;

    if( exist_boolArray( array ) )
    {
        if( 0 <= index && index < array->size ) 
        {
            value = array->data[index];
        } // end if
    } // end if

    return ( value );
} // end get_bool_boolArray ( )

/**
 *  Copiar um arranjo booleano para outro arranjo booleano.
 *  @return cópia do arranjo.
*/
boolArray* copy_boolArray( boolArray* array )
{
    boolArray* copy = NULL;
    
    if( !exist_boolArray( array ) )
    {
        printf( "\n%s\n", "[ERRO]: Missing datas." );
    }
    else
    {
        if( array->size <= 0 )
        {
            printf( "\n%s\n", "[ERRO]: Invalid size." );
        }
        else
        {
            copy = new_boolArray( array->size );

            if( copy != NULL )
            {
                for( copy->ix = 0; copy->ix < copy->size; copy->ix =copy->ix + 1 )
                {
                    copy->data[copy->ix] = array->data[copy->ix];
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_boolArray ( )

// ---------------------------------- Fim
#endif
