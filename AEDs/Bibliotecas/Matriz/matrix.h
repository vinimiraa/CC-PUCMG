/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca Matrix em C - "matrix.h"
 *  ----------------------------------------------------------------------------
*/

// ---------------------- lista de dependencias

#include <stdio.h>   // para entradas e saidas
#include <stdlib.h>  // para a biblioteca padrao
#include <stddef.h>  // para definicoes basicas
#include <stdarg.h>  // para tratar argumentos
#include <string.h>  // para cadeias de caracteres
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters

// ---------------------- redefinicoes uteis

#ifndef __MATRIX_H__
#define __MATRIX_H__

// ---------------------- definicoes de constantes

const int MAX_SIZE = 10 ;  // definir tamanho padrao para matrizes

// ---------------------- definicoes de variaveis globais

#define bool  int
#define false 0
#define true (!false)

typedef struct s_intMatrix
{
    int row;
    int col;
    int** data;
    int ix,iy;
} intMatrix;

/**
    Definicao de referencia para matriz com inteiros baseado em estrutura
*/
typedef intMatrix* ref_intMatrix;

typedef struct s_doubleMatrix
{
    int row;
    int col;
    double** data;
    int ix,iy;
} doubleMatrix;

/**
    Definicao de referencia para matriz real baseado em estrutura
*/
typedef doubleMatrix* ref_doubleMatrix;

typedef struct s_boolMatrix
{
    int row;
    int col;
    bool** data;
    int ix,iy;
} boolMatrix;

/**
    Definicao de referencia para matriz booleana baseado em estrutura
*/
typedef boolMatrix* ref_boolMatrix;

// ---------------------- intMatrix

/**
 *  Verifica se a matriz de inteiros e os dados existem.
 *  @return TRUE : se existem; FALSE : caso contrario.
*/
bool exist_intMatrix( intMatrix* matrix )
{
    bool result = false;
    if( matrix != NULL && matrix->data != NULL )
    {
        result = true;
    } // end if
    return ( result );
} // end exist_intMatrix ( )

/**
 *  Cria e aloca o espaço de memória para uma matriz de inteiros.
 *  @return MATRIZ.
*/
intMatrix* new_intMatrix( int rows, int columns )
{
    intMatrix *matrix = ( intMatrix* ) malloc ( 1 * sizeof( intMatrix ) );
    
    if( matrix != NULL )
    {
        matrix->row = 0;
        matrix->col = 0;
        matrix->data = NULL;
        
        if ( rows > 0 && columns > 0 )
        {
            matrix->row = rows;
            matrix->col = columns;
            matrix->data = ( int** ) malloc( rows * sizeof( int* ) );
            
            if ( matrix->data )
            {
                for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
                {
                    matrix->data[matrix->ix] = ( int* ) malloc( columns * sizeof( int ) );
                } // end for
            } // end if
        } // end if
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if

    return ( matrix );
} // end new_intMatrix ( )

/**
 *  Inicializa uma matriz de inteiros com um valor. 
*/
void init_intMatrix( intMatrix* matrix, int init_value )
{
    if( exist_intMatrix( matrix ) )
    {
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                matrix->data[matrix->ix][matrix->iy] = init_value;
            } // end for
        } // end for
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if
} // end init_intMatrix ( )

/**
 *  Libera o espaço de memória de uma matriz de inteiros.
*/
void free_intMatrix( intMatrix* matrix )
{
    if ( exist_intMatrix( matrix ) )
    {
        for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
        {
            free(matrix->data[matrix->ix]);
        } // end for
        free(matrix->data);
        free(matrix);
    } // end if
} // end free_intMatrix ( )

/**
 *  Mostra uma matriz com valores inteiros.
*/
void print_intMatrix( intMatrix* matrix )
{
    if ( exist_intMatrix( matrix ) )
    {
        for ( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for ( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                printf( "%3d\t", matrix->data[matrix->ix][matrix->iy] );
            } // end for
            printf( "\n" );
        } // end for
    } // end if
} // end print_intMatrix ( )

/**
 *  Lê os dados de uma matriz de inteiros.
 *  @return MATRIZ com os dados lidos.
*/
intMatrix* read_intMatrix( )
{
    intMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;

    do
    {
        printf( "\n%s" , "Rows = " );
        scanf( "%d", &rows ); 
        getchar( );
    }while( rows <= 0 );
    do
    {
        printf( "\n%s", "Columns = " );
        scanf( "%d", &columns );
        getchar( );
    } while ( columns <= 0 );

    matrix = new_intMatrix( rows, columns );

    if( matrix != NULL )
    {
        if( matrix->data == NULL )
        {
            matrix->row = 0;
            matrix->col = 0;
            matrix->ix  = 0;
            matrix->iy  = 0;
        }
        else
        {
            for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
            {
                for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
                {
                    printf( "%2d, %2d: ", matrix->ix, matrix->iy );
                    scanf( "%d", &matrix->data[matrix->ix][matrix->iy] );
                    getchar( );
                } // end for
            } // end for
        } // end if
    } // end if

    return ( matrix );
} // end read_intMatrix ( )

/**
 *  Grava em um arquivo uma matriz de inteiros.
*/
void fprint_intMatrix( char* filename , intMatrix* matrix )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_intMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: the matrix does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", matrix->row );
        fprintf( file, "%d\n", matrix->col );
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                fprintf( file, "%d\n", matrix->data[matrix->ix][matrix->iy] );
            } // end for
        } // end for

        fclose( file );
    } // end if
} // end fprint_intMatrix ( )

/**
 *  Lê de um arquivo uma matriz de inteiros.
 *  @return MATRIZ com os valores lidos do arquivo.
*/
intMatrix* fread_intMatrix( char* filename )
{
    FILE *file = fopen( filename, "rt" );
    intMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;
    
    if ( file == NULL )
    {
        printf( "\n%s\n", "ERROR: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &rows ); fgetc( file );
        fscanf( file, "%d", &columns ); fgetc( file );

        if ( rows <= 0 || columns <= 0 )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            matrix = new_intMatrix( rows, columns );

            if ( matrix != NULL && matrix->data == NULL )
            {
                matrix->row = 0;
                matrix->col = 0;
                matrix->ix = 0;
                matrix->iy = 0;
            }
            else
            {
                if ( matrix != NULL )
                {
                    matrix->ix = 0;
                    while ( !feof( file ) && matrix->ix < matrix->row )
                    {
                        matrix->iy = 0;
                        while ( !feof( file ) && matrix->iy < matrix->col )
                        {
                            fscanf( file, "%d", &( matrix->data[matrix->ix][matrix->iy] ) );
                            fgetc( file );
                            matrix->iy = matrix->iy + 1;
                        } // end while
                        matrix->ix = matrix->ix + 1;
                    } // end while
                    matrix->ix = 0;
                    matrix->iy = 0;
                } // end if
            } // end if
        } // end if
    } // end if
    fclose ( file );
    
    return (matrix);
} // end fread_intMatrix ( ) 

/**
 *  Método para definir um valor inteiro específico da matriz inteiros.
*/
void set_int_intMatrix( intMatrix* matrix, int row, int col, int value )
{
    if ( exist_intMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            matrix->data[row][col] = value;
        } // end if
    } // end if
} // end set_int_intMatrix ( )

/**
 *  Método para pegar um valor inteiro específico da matriz inteiros.
*/
int get_int_intMatrix( intMatrix* matrix, int row, int col )
{
    int value = 0.0;
    if ( exist_intMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            value = matrix->data[row][col];
        } // end if
    } // end if
    return ( value );
} // end get_int_intMatrix ( )

/**
 *  Faz a transposição de uma matriz de inteiros.
 *  @return MATRIZ transposta.
*/
intMatrix* transpose_intMatrix( intMatrix* matrix ) 
{
    intMatrix* transposed = NULL;
    int rows = 0;
    int columns = 0;
    
    if( exist_intMatrix( matrix ) )
    {
        rows = matrix->col;
        columns = matrix->row;

        transposed = new_intMatrix( rows, columns );
        
        if( transposed != NULL && transposed->data == NULL )
        {
            transposed->row = 0;
            transposed->col = 0;
            transposed->ix  = 0;
            transposed->iy  = 0;
        }
        else
        {
            if( transposed != NULL )
            {
                transposed->ix = 0;
                while( transposed->ix < transposed->row )
                {
                    transposed->iy = 0;
                    while( transposed->iy < transposed->col )
                    {
                        transposed->data[transposed->ix][transposed->iy] = matrix->data[transposed->iy][transposed->ix];
                        transposed->iy = transposed->iy + 1;
                    } // end while
                    transposed->ix = transposed->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if
    
    return ( transposed ) ;
} // end transpose_intMatrix ( )

/**
 *  Verifica se a matriz de inteiros só tem zeros.
 *  @return TRUE : se só tem zeros; FALSE : caso contrário.
*/
bool iszero_intMatrix ( intMatrix* matrix )
{
    bool result = true;

    if( exist_intMatrix( matrix ) )
    {
        matrix->ix = 0;
        while( matrix->ix < matrix->row && !result )
        {
            matrix->iy = 0;
            while( matrix->iy < matrix->col && !result )
            {
                if( matrix->data[matrix->ix][matrix->iy] != 0 )
                {
                    result = false;
                } // end if
                matrix->iy = matrix->iy + 1;
            } // end while
            matrix->ix = matrix->ix + 1;
        } // end while
    } // end if

    return ( result );
} // end iszero_intMatrix ( )

/**
 *  Verifica se duas matrizes de inteiros são iguais.
 *  @return TRUE : se iguais; FALSE : caso contrário. 
*/
bool compare_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    bool result = true;

    if( exist_intMatrix( matrix1 ) && exist_intMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
            result = false;
        }
        else
        {
            matrix1->ix = 0;
            while( matrix1->ix < matrix1->row && !result )
            {
                matrix1->iy = 0;
                while( matrix1->iy < matrix1->col && !result )
                {
                    if( matrix1->data[matrix1->ix][matrix1->iy] !=
                        matrix2->data[matrix1->ix][matrix1->iy] )
                    {
                        result = false;
                    } // end if
                    matrix1->iy = matrix1->iy + 1; 
                } // end while
                matrix1->ix = matrix1->ix + 1; 
            } // end while
        } // end if
    } // end if

    return ( result );
} // end compare_intMatrix ( )

/**
    Copia uma matriz com valores inteiros.
    @return cópia da MATRIZ;
*/
intMatrix* copy_intMatrix( intMatrix* matrix )
{
    intMatrix* copy = NULL;

    if ( !exist_intMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: Missing data." );
    }
    else
    {
        if (matrix->row <= 0 || matrix->col <= 0)
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            copy = new_intMatrix( matrix->row, matrix->col );

            if ( exist_intMatrix( copy ) )
            {
                for (copy->ix = 0; copy->ix < copy->row; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->col; copy->iy = copy->iy + 1)
                    {
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_intMatrix ( )

/**
 *  Soma duas matrizes de inteiros.
 *  @return MATRIZ resultante da soma.
*/
intMatrix* add_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( exist_intMatrix( matrix1 ) && exist_intMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_intMatrix( matrix1->row, matrix1->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] =   matrix1->data[aux->ix][aux->iy] +
                                                        matrix2->data[aux->ix][aux->iy];
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end add_intMatrix ( )

/**
 *  Faz a diferença de duas matrizes de inteiros.
 *  @return MATRIZ resultante da diferença.
*/
intMatrix* diff_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( exist_intMatrix( matrix1 ) && exist_intMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_intMatrix( matrix1->row, matrix1->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] =   matrix1->data[aux->ix][aux->iy] -
                                                        matrix2->data[aux->ix][aux->iy];
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end diff_intMatrix ( )

/**
 *  Faz o produto de duas matrizes de inteiros.
 *  @return MATRIZ resultante do produto.
*/
intMatrix* product_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( exist_intMatrix( matrix1) && exist_intMatrix( matrix2 ) )
    {
        if( matrix1->col != matrix2->row ) 
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_intMatrix( matrix1->row, matrix2->col );

            if( exist_intMatrix( aux ) )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] = 0;

                        matrix1->ix = 0;
                        while( matrix1->ix < matrix1->col )
                        {
                            aux->data[aux->ix][aux->iy] +=  matrix1->data[aux->ix][matrix1->ix] *
                                                            matrix2->data[matrix1->ix][aux->iy];
                            matrix1->ix = matrix1->ix + 1;
                        } // end while
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end product_intMatrix ( )

/**
 *  Multiplica cada elemento de uma matriz de inteiros por uma constante inteira.
 *  @return MATRIZ resultante.
*/
intMatrix* scalar_intMatrix( intMatrix* matrix, int k )
{
    intMatrix* aux = NULL;
    if ( exist_intMatrix( matrix ) )
    {
        aux = new_intMatrix( matrix->row, matrix->col );
        if( exist_intMatrix( aux ) )
        {
            for( aux->ix = 0; aux->ix < aux->row; aux->ix = aux->ix + 1 )
            {
                for( aux->iy = 0; aux->iy < aux->col; aux->iy = aux->iy + 1 )
                {
                    aux->data[aux->ix][aux->iy] = matrix->data[aux->ix][aux->iy] * k;
                } // end for
            } // end for
        } // end if
    } // end if

    return ( aux );
} // end scalar_intMatrix ( )

// ---------------------- doubleMatrix

/**
 *  Verifica se a matriz real e os dados existem.
 *  @return TRUE : se existem; FALSE : caso contrario.
*/
bool exist_doubleMatrix( doubleMatrix* matrix )
{
    bool result = false;
    if( matrix != NULL && matrix->data != NULL )
    {
        result = true;
    } // end if
    return ( result );
} // end exist_doubleMatrix ( )

/**
 *  Cria e aloca o espaço de memória para uma matriz real.
 *  @return MATRIZ.
*/
doubleMatrix* new_doubleMatrix( int rows, int columns )
{
    doubleMatrix *matrix = ( doubleMatrix* ) malloc ( 1 * sizeof( doubleMatrix ) );
    
    if( matrix != NULL )
    {
        matrix->row = 0;
        matrix->col = 0;
        matrix->data = NULL;
        
        if ( rows > 0 && columns > 0 )
        {
            matrix->row = rows;
            matrix->col = columns;
            matrix->data = ( double** ) malloc( rows * sizeof( double* ) );
            
            if ( matrix->data )
            {
                for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
                {
                    matrix->data[matrix->ix] = ( double* ) malloc( columns * sizeof( double ) );
                } // end for
            } // end if
        } // end if
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if

    return ( matrix );
} // end new_doubleMatrix ( )

/**
 *  Inicializa uma matriz real com um valor. 
*/
void init_doubleMatrix( doubleMatrix* matrix, double init_value )
{
    if( exist_doubleMatrix( matrix ) )
    {
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                matrix->data[matrix->ix][matrix->iy] = init_value;
            } // end for
        } // end for
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if
} // end init_doubleMatrix ( )

/**
 *  Libera o espaço de memória de uma matriz real.
*/
void free_doubleMatrix( doubleMatrix* matrix )
{
    if ( exist_doubleMatrix( matrix ) )
    {
        for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
        {
            free(matrix->data[matrix->ix]);
        } // end for
        free(matrix->data);
        free(matrix);
    } // end if
} // end free_doubleMatrix ( )

/**
 *  Mostra uma matriz com valores reais.
*/
void print_doubleMatrix( doubleMatrix* matrix )
{
    if ( exist_doubleMatrix( matrix ) )
    {
        for ( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for ( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                printf( "%.2lf\t", matrix->data[matrix->ix][matrix->iy] );
            } // end for
            printf( "\n" );
        } // end for
    } // end if
} // end print_doubleMatrix ( )

/**
 *  Lê os dados de uma matriz real.
 *  @return MATRIZ com os dados lidos.
*/
doubleMatrix* read_doubleMatrix( )
{
    doubleMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;

    do
    {
        printf( "\n%s" , "Rows = " );
        scanf( "%d", &rows ); 
        getchar( );
    }while( rows <= 0 );
    do
    {
        printf( "\n%s", "Columns = " );
        scanf( "%d", &columns );
        getchar( );
    } while ( columns <= 0 );

    matrix = new_doubleMatrix( rows, columns );

    if( matrix != NULL )
    {
        if( matrix->data == NULL )
        {
            matrix->row = 0;
            matrix->col = 0;
            matrix->ix  = 0;
            matrix->iy  = 0;
        }
        else
        {
            for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
            {
                for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
                {
                    printf( "%2d, %2d: ", matrix->ix, matrix->iy );
                    scanf( "%lf", &matrix->data[matrix->ix][matrix->iy] );
                    getchar( );
                } // end for
            } // end for
        } // end if
    } // end if

    return ( matrix );
} // end read_doubleMatrix ( )

/**
 *  Grava em um arquivo uma matriz real.
*/
void fprint_doubleMatrix( char* filename , doubleMatrix* matrix )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_doubleMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: the matrix does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", matrix->row );
        fprintf( file, "%d\n", matrix->col );
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                fprintf( file, "%lf\n", matrix->data[matrix->ix][matrix->iy] );
            } // end for
        } // end for

        fclose( file );
    } // end if
} // end fprint_doubleMatrix ( )

/**
 *  Lê de um arquivo uma matriz real.
 *  @return MATRIZ com os valores lidos do arquivo.
*/
doubleMatrix* fread_doubleMatrix( char* filename )
{
    FILE *file = fopen( filename, "rt" );
    doubleMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;
    
    if ( file == NULL )
    {
        printf( "\n%s\n", "ERROR: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &rows ); fgetc( file );
        fscanf( file, "%d", &columns ); fgetc( file );

        if ( rows <= 0 || columns <= 0 )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            matrix = new_doubleMatrix( rows, columns );

            if ( matrix != NULL && matrix->data == NULL )
            {
                matrix->row = 0;
                matrix->col = 0;
                matrix->ix = 0;
                matrix->iy = 0;
            }
            else
            {
                if ( matrix != NULL )
                {
                    matrix->ix = 0;
                    while ( !feof( file ) && matrix->ix < matrix->row )
                    {
                        matrix->iy = 0;
                        while ( !feof( file ) && matrix->iy < matrix->col )
                        {
                            fscanf( file, "%lf", &( matrix->data[matrix->ix][matrix->iy] ) );
                            fgetc( file );
                            matrix->iy = matrix->iy + 1;
                        } // end while
                        matrix->ix = matrix->ix + 1;
                    } // end while
                    matrix->ix = 0;
                    matrix->iy = 0;
                } // end if
            } // end if
        } // end if
    } // end if
    fclose ( file );
    
    return (matrix);
} // end fread_doubleMatrix ( )

/**
 *  Método para definir um valor real específico da matriz real.
*/
void set_double_doubleMatrix( doubleMatrix* matrix, int row, int col, double value )
{
    if ( exist_doubleMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            matrix->data[row][col] = value;
        } // end if
    } // end if
} // end set_double_doubleMatrix ( )

/**
 *  Método para pegar um valor real específico da matriz real.
*/
double get_double_doubleMatrix( doubleMatrix* matrix, int row, int col )
{
    double value = 0.0;
    if ( exist_doubleMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            value = matrix->data[row][col];
        } // end if
    } // end if
    return ( value );
} // end get_double_doubleMatrix ( )

/**
 *  Faz a transposição de uma matriz real.
 *  @return MATRIZ transposta.
*/
doubleMatrix* transpose_doubleMatrix( doubleMatrix* matrix ) 
{
    doubleMatrix* transposed = NULL;
    int rows = 0;
    int columns = 0;
    
    if( exist_doubleMatrix( matrix ) )
    {
        rows = matrix->col;
        columns = matrix->row;

        transposed = new_doubleMatrix( rows, columns );
        
        if( transposed != NULL && transposed->data == NULL )
        {
            transposed->row = 0;
            transposed->col = 0;
            transposed->ix  = 0;
            transposed->iy  = 0;
        }
        else
        {
            if( transposed != NULL )
            {
                transposed->ix = 0;
                while( transposed->ix < transposed->row )
                {
                    transposed->iy = 0;
                    while( transposed->iy < transposed->col )
                    {
                        transposed->data[transposed->ix][transposed->iy] = matrix->data[transposed->iy][transposed->ix];
                        transposed->iy = transposed->iy + 1;
                    } // end while
                    transposed->ix = transposed->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if
    
    return ( transposed ) ;
} // end transpose_doubleMatrix ( )

/**
 *  Verifica se a matriz real só tem zeros.
 *  @return TRUE : se só tem zeros; FALSE : caso contrário.
*/
bool iszero_doubleMatrix ( doubleMatrix* matrix )
{
    bool result = true;

    if( exist_doubleMatrix( matrix ) )
    {
        matrix->ix = 0;
        while( matrix->ix < matrix->row && !result )
        {
            matrix->iy = 0;
            while( matrix->iy < matrix->col && !result )
            {
                if( matrix->data[matrix->ix][matrix->iy] != 0.0 )
                {
                    result = false;
                } // end if
                matrix->iy = matrix->iy + 1;
            } // end while
            matrix->ix = matrix->ix + 1;
        } // end while
    } // end if

    return ( result );
} // end iszero_doubleMatrix ( )

/**
 *  Verifica se duas matrizes reais são iguais.
 *  @return TRUE : se iguais; FALSE : caso contrário. 
*/
bool compare_doubleMatrix( doubleMatrix* matrix1, doubleMatrix* matrix2 )
{
    bool result = true;

    if( exist_doubleMatrix( matrix1 ) && exist_doubleMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
            result = false;
        }
        else
        {
            matrix1->ix = 0;
            while( matrix1->ix < matrix1->row && !result )
            {
                matrix1->iy = 0;
                while( matrix1->iy < matrix1->col && !result )
                {
                    if( matrix1->data[matrix1->ix][matrix1->iy] !=
                        matrix2->data[matrix1->ix][matrix1->iy] )
                    {
                        result = false;
                    } // end if
                    matrix1->iy = matrix1->iy + 1; 
                } // end while
                matrix1->ix = matrix1->ix + 1; 
            } // end while
        } // end if
    } // end if

    return ( result );
} // end compare_doubleMatrix ( )

/**
    Copia uma matriz com valores reais.
    @return cópia da MATRIZ;
*/
doubleMatrix* copy_doubleMatrix( doubleMatrix* matrix )
{
    doubleMatrix* copy = NULL;

    if ( !exist_doubleMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: Missing data." );
    }
    else
    {
        if (matrix->row <= 0 || matrix->col <= 0)
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            copy = new_doubleMatrix( matrix->row, matrix->col );

            if ( exist_doubleMatrix( copy ) )
            {
                for (copy->ix = 0; copy->ix < copy->row; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->col; copy->iy = copy->iy + 1)
                    {
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_doubleMatrix ( )

/**
 *  Soma duas matrizes reais.
 *  @return MATRIZ resultante da soma.
*/
doubleMatrix* add_doubleMatrix( doubleMatrix* matrix1, doubleMatrix* matrix2 )
{
    doubleMatrix* aux = NULL;

    if( exist_doubleMatrix( matrix1 ) && exist_doubleMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_doubleMatrix( matrix1->row, matrix1->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] =   matrix1->data[aux->ix][aux->iy] +
                                                        matrix2->data[aux->ix][aux->iy];
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end add_doubleMatrix ( )

/**
 *  Faz a diferença de duas matrizes reais.
 *  @return MATRIZ resultante da diferença.
*/
doubleMatrix* diff_doubleMatrix( doubleMatrix* matrix1, doubleMatrix* matrix2 )
{
    doubleMatrix* aux = NULL;

    if( exist_doubleMatrix( matrix1 ) && exist_doubleMatrix( matrix2 ) )
    {
        if( matrix1->row != matrix2->row && matrix1->col != matrix2->col )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_doubleMatrix( matrix1->row, matrix1->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] =   matrix1->data[aux->ix][aux->iy] -
                                                        matrix2->data[aux->ix][aux->iy];
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end diff_doubleMatrix ( )

/**
 *  Faz o produto de duas matrizes reais.
 *  @return MATRIZ resultante do produto.
*/
doubleMatrix* product_doubleMatrix( doubleMatrix* matrix1, doubleMatrix* matrix2 )
{
    doubleMatrix* aux = NULL;

    if( exist_doubleMatrix( matrix1) && exist_doubleMatrix( matrix2 ) )
    {
        if( matrix1->col != matrix2->row ) 
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            aux = new_doubleMatrix( matrix1->row, matrix2->col );

            if( exist_doubleMatrix( aux ) )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] = 0;

                        matrix1->ix = 0;
                        while( matrix1->ix < matrix1->col )
                        {
                            aux->data[aux->ix][aux->iy] +=  matrix1->data[aux->ix][matrix1->ix] *
                                                            matrix2->data[matrix1->ix][aux->iy];
                            matrix1->ix = matrix1->ix + 1;
                        } // end while
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end product_doubleMatrix ( )

/**
 *  Multiplica cada elemento de uma matriz real por uma constante real.
 *  @return MATRIZ resultante.
*/
doubleMatrix* scalar_doubleMatrix( doubleMatrix* matrix, double k )
{
    doubleMatrix* aux = NULL;
    if ( exist_doubleMatrix( matrix ) )
    {
        aux = new_doubleMatrix( matrix->row, matrix->col );
        if( exist_doubleMatrix( aux ) )
        {
            for( aux->ix = 0; aux->ix < aux->row; aux->ix = aux->ix + 1 )
            {
                for( aux->iy = 0; aux->iy < aux->col; aux->iy = aux->iy + 1 )
                {
                    aux->data[aux->ix][aux->iy] = matrix->data[aux->ix][aux->iy] * k;
                } // end for
            } // end for
        } // end if
    } // end if

    return ( aux );
} // end scalar_doubleMatrix ( )

// ---------------------- boolMatrix

/**
 *  Verifica se a matriz booleana e os dados existem.
 *  @return TRUE : se existem; FALSE : caso contrario.
*/
bool exist_boolMatrix( boolMatrix* matrix )
{
    bool result = false;
    if( matrix != NULL && matrix->data != NULL )
    {
        result = true;
    } // end if
    return ( result );
} // end exist_boolMatrix ( )

/**
 *  Cria e aloca o espaço de memória para uma matriz booleana.
 *  @return MATRIZ.
*/
boolMatrix* new_boolMatrix( int rows, int columns )
{
    boolMatrix *matrix = ( boolMatrix* ) malloc ( 1 * sizeof( boolMatrix ) );
    
    if( matrix != NULL )
    {
        matrix->row = 0;
        matrix->col = 0;
        matrix->data = NULL;
        
        if ( rows > 0 && columns > 0 )
        {
            matrix->row = rows;
            matrix->col = columns;
            matrix->data = ( bool** ) malloc( rows * sizeof( bool* ) );
            
            if ( matrix->data )
            {
                for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
                {
                    matrix->data[matrix->ix] = ( bool* ) malloc( columns * sizeof( bool ) );
                } // end for
            } // end if
        } // end if
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if

    return ( matrix );
} // end new_boolMatrix ( )

/**
 *  Inicializa uma matriz booleana com um valor. 
*/
void init_boolMatrix( boolMatrix* matrix, bool init_value )
{
    if( exist_boolMatrix( matrix ) )
    {
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                matrix->data[matrix->ix][matrix->iy] = init_value;
            } // end for
        } // end for
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if
} // end init_boolMatrix ( )

/**
 *  Libera o espaço de memória de uma matriz booleana.
*/
void free_boolMatrix( boolMatrix* matrix )
{
    if ( exist_boolMatrix( matrix ) )
    {
        for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
        {
            free(matrix->data[matrix->ix]);
        } // end for
        free(matrix->data);
        free(matrix);
    } // end if
} // end free_boolMatrix ( )

/**
 *  Mostra uma matriz com valores booleanos.
*/
void print_boolMatrix( boolMatrix* matrix )
{
    if ( exist_boolMatrix( matrix ) )
    {
        for ( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for ( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                printf( "%d\t", matrix->data[matrix->ix][matrix->iy] );
            } // end for
            printf( "\n" );
        } // end for
    } // end if
} // end print_boolMatrix ( )

/**
 *  Lê os dados de uma matriz booleana.
 *  @return MATRIZ com os dados lidos.
*/
boolMatrix* read_boolMatrix( )
{
    boolMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;

    do
    {
        printf( "\n%s" , "Rows = " );
        scanf( "%d", &rows ); 
        getchar( );
    }while( rows <= 0 );
    do
    {
        printf( "\n%s", "Columns = " );
        scanf( "%d", &columns );
        getchar( );
    } while ( columns <= 0 );

    matrix = new_boolMatrix( rows, columns );

    if( matrix != NULL )
    {
        if( matrix->data == NULL )
        {
            matrix->row = 0;
            matrix->col = 0;
            matrix->ix  = 0;
            matrix->iy  = 0;
        }
        else
        {
            for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
            {
                for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
                {
                    printf( "%2d, %2d: ", matrix->ix, matrix->iy );
                    scanf( "%d", &matrix->data[matrix->ix][matrix->iy] );
                    getchar( );
                } // end for
            } // end for
        } // end if
    } // end if

    return ( matrix );
} // end read_boolMatrix ( )

/**
 *  Grava em um arquivo uma matriz booleana.
*/
void fprint_boolMatrix( char* filename , boolMatrix* matrix )
{
    FILE* file = fopen( filename, "wt" );

    if( !exist_boolMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: the matrix does not exist." );
    }
    else
    {
        fprintf( file, "%d\n", matrix->row );
        fprintf( file, "%d\n", matrix->col );
        for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1 )
        {
            for( matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1 )
            {
                fprintf( file, "%d\n", matrix->data[matrix->ix][matrix->iy] );
            } // end for
        } // end for

        fclose( file );
    } // end if
} // end fprint_boolMatrix ( )

/**
 *  Lê de um arquivo uma matriz booleana.
 *  @return MATRIZ com os valores lidos do arquivo.
*/
boolMatrix* fread_boolMatrix( char* filename )
{
    FILE *file = fopen( filename, "rt" );
    boolMatrix* matrix = NULL;
    int rows = 0;
    int columns = 0;
    
    if ( file == NULL )
    {
        printf( "\n%s\n", "ERROR: Unable to open the file." );
    }
    else
    {
        fscanf( file, "%d", &rows ); fgetc( file );
        fscanf( file, "%d", &columns ); fgetc( file );

        if ( rows <= 0 || columns <= 0 )
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            matrix = new_boolMatrix( rows, columns );

            if ( matrix != NULL && matrix->data == NULL )
            {
                matrix->row = 0;
                matrix->col = 0;
                matrix->ix = 0;
                matrix->iy = 0;
            }
            else
            {
                if ( matrix != NULL )
                {
                    matrix->ix = 0;
                    while ( !feof( file ) && matrix->ix < matrix->row )
                    {
                        matrix->iy = 0;
                        while ( !feof( file ) && matrix->iy < matrix->col )
                        {
                            fscanf( file, "%d", &( matrix->data[matrix->ix][matrix->iy] ) );
                            fgetc( file );
                            matrix->iy = matrix->iy + 1;
                        } // end while
                        matrix->ix = matrix->ix + 1;
                    } // end while
                    matrix->ix = 0;
                    matrix->iy = 0;
                } // end if
            } // end if
        } // end if
    } // end if
    fclose ( file );
    
    return (matrix);
} // end fread_boolMatrix ( )

/**
 *  Realiza a operação lógica AND entre duas matrizes booleanas.
 *  @return MATRIZ resultante da operação AND.
 */
boolMatrix* and_boolMatrix( boolMatrix* matrix1, boolMatrix* matrix2 )
{
    boolMatrix* result = NULL;

    if( exist_boolMatrix( matrix1 ) && exist_boolMatrix( matrix2 ) ) 
    {
        if( matrix1->row == matrix2->row && matrix1->col == matrix2->col )
        {
            result = new_boolMatrix( matrix1->row, matrix1->col );

            if( exist_boolMatrix( result ) )
            {
                for( result->ix = 0; result->ix < result->row; result->ix = result->ix + 1) 
                {
                    for( result->iy = 0; result->iy < result->col; result->iy = result->iy + 1 ) 
                    {
                        result->data[result->ix][result->iy] =
                                matrix1->data[result->ix][result->iy] &&
                                matrix2->data[result->ix][result->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( result );
} // end and_boolMatrix ( )

/**
 *  Realiza a operação lógica OR entre duas matrizes booleanas.
 *  @return MATRIZ resultante da operação OR.
 */
boolMatrix* or_boolMatrix( boolMatrix* matrix1, boolMatrix* matrix2 ) 
{
    boolMatrix* result = NULL;

    if( exist_boolMatrix( matrix1 ) && exist_boolMatrix( matrix2 ) ) 
    {
        if( matrix1->row == matrix2->row && matrix1->col == matrix2->col )
        {
            result = new_boolMatrix(matrix1->row, matrix1->col);

            if ( exist_boolMatrix( result ) ) 
            {
                for( result->ix = 0; result->ix < result->row; result->ix = result->ix + 1 ) 
                {
                    for( result->iy = 0; result->iy < result->col; result->iy = result->iy + 1 ) 
                    {
                        result->data[result->ix][result->iy] =
                                matrix1->data[result->ix][result->iy] ||
                                matrix2->data[result->ix][result->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( result );
} // end or_boolMatrix ( )

/**
 *  Realiza a operação lógica NOT em uma matriz booleana.
 *  @return MATRIZ resultante da operação NOT.
 */
boolMatrix* not_boolMatrix( boolMatrix* matrix ) 
{
    boolMatrix* result = NULL;

    if ( exist_boolMatrix( matrix ) ) 
    {
        result = new_boolMatrix( matrix->row, matrix->col );

        if ( exist_boolMatrix( result ) ) 
        {
            for( result->ix = 0; result->ix < result->row; result->ix = result->ix +1 ) 
            {
                for( result->iy = 0; result->iy < result->col; result->iy = result->iy +1 ) 
                {
                    result->data[result->ix][result->iy] = !matrix->data[result->ix][result->iy];
                } // end for
            } // end for
        } // end if
    } // end if

    return ( result );
} // end not_boolMatrix ( )

/**
 *  Método para definir um bit específico da matriz.
*/
void set_bit_boolMatrix( boolMatrix* matrix, int row, int col )
{
    if ( exist_boolMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            matrix->data[row][col] = true;
        } // end if
    } // end if
} // end set_bit_boolMatrix ( )

/**
 *  Método para pegar um bit específico da matriz booleana.
*/
int get_bit_boolMatrix( boolMatrix* matrix, int row, int col )
{
    int value = 0.0;
    if ( exist_boolMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            value = matrix->data[row][col];
        } // end if
    } // end if
    return ( value );
} // end get_bit_boolMatrix ( )

/**
 *  Método para limpar um bit específico da matriz.
*/
void clear_bit_boolMatrix( boolMatrix* matrix, int row, int col )
{
    if ( exist_boolMatrix( matrix ) ) 
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            matrix->data[row][col] = true;
        } // end if
    } // end if
} // end clear_bit_boolMatrix ( )

/**
 *  Testar o valor do bit na posição específica.
 *  @return TRUE : bit iguai a 1; FALSE : caso contrário.
*/
bool test_bit_boolMatrix( boolMatrix* matrix, int row, int col ) 
{
    bool result = false;
    if( exist_boolMatrix( matrix ) )
    {
        if( row >= 0 && row < matrix->row && col >= 0 && col < matrix->col )
        {
            if( matrix->data[row][col] )
            {
                result = true;
            }
        }
    }

    return ( result );
} // end test_bit_boolMatrix ( )

/**
    Copia uma matriz com valores booleanos.
    @return cópia da MATRIZ;
*/
boolMatrix* copy_boolMatrix( boolMatrix* matrix )
{
    boolMatrix* copy = NULL;

    if ( !exist_boolMatrix( matrix ) )
    {
        printf( "\n%s\n", "ERROR: Missing data." );
    }
    else
    {
        if (matrix->row <= 0 || matrix->col <= 0)
        {
            printf( "\n%s\n", "ERROR: Invalid size." );
        }
        else
        {
            copy = new_boolMatrix( matrix->row, matrix->col );

            if ( exist_boolMatrix( copy ) )
            {
                for (copy->ix = 0; copy->ix < copy->row; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->col; copy->iy = copy->iy + 1)
                    {
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( copy );
} // end copy_boolMatrix ( )

// ---------------------- fim
#endif
