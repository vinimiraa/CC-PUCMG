/**
 *  ----------------------------------------------------------------------------
 *  Biblioteca para Manipulação de Strings em C - "cstring.h"
 *  ----------------------------------------------------------------------------
*/

// --------------------------- Libs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

// --------------------------- Preprocessor

#ifndef __STR_H__
#define __STR_H__

// --------------------------- Prototypes

/**
 *  @brief  Retorna o tamanho da string.
 *  @param  str Ponteiro para a string.
 *  @return Tamanho da string.
 */
size_t str_len( const char *str );

/**
 *  @brief  Copia a string de origem para a string de destino.
 *  @param  dst Ponteiro para a string de destino.
 *  @param  src Ponteiro para a string de origem.
 *  @return Ponteiro para a string de destino.
 */
char* str_copy( char *dst, const char* src );

/**
 *  @brief  Concatena duas strings.
 *  @param  str1 Ponteiro para a primeira string.
 *  @param  str2 Ponteiro para a segunda string.
 *  @return Ponteiro para a string concatenada.
 */
char* str_concat( const char *str1, const char *str2 );

/**
 *  @brief  Procura a primeira ocorrência do caractere na string.
 *  @param  str Ponteiro para a string.
 *  @param  chr Caractere a ser procurado.
 *  @return Ponteiro para a primeira ocorrência do caractere na string.
 */
char* str_char( const char* str, const int chr );

/**
 *  @brief  Pega parte de uma string.
 *  @param  str Ponteiro para a string.
 *  @param  start Posição inicial.
 *  @param  end Posição final.
 *  @return Ponteiro para a substring.
 */
char* str_substring( const char *str, size_t start, size_t end );

/**
 *  @brief  Divide a string em partes.
 *  @param  str Ponteiro para a string.
 *  @param  delimiter Caractere delimitador.
 *  @return Ponteiro para a lista de strings.
 */
char** str_split( char* str, const char delimiter );

/**
 *  @brief  Procura a primeira ocorrência do caractere na string.
 *  @param  str Ponteiro para a string.
 *  @param  chr Caractere a ser procurado.
 *  @return Índice da primeira ocorrência do caractere na string.
 */
size_t str_first_index_of( const char *str, const char chr );

/**
 *  @brief  Procura a última ocorrência do caractere na string.
 *  @param  str Ponteiro para a string.
 *  @param  chr Caractere a ser procurado.
 *  @return Índice da última ocorrência do caractere na string.
 */
size_t str_last_index_of( const char *str, const char chr );

/**
 *  @brief  Retira caracteres em branco à esquerda da string.
 *  @param  str Ponteiro para a string.
 *  @return Ponteiro para a string.
 */
char* str_left_trim( char* str );

/**
 *  @brief  Retira caracteres em branco à direita da string.
 *  @param  str Ponteiro para a string.
 *  @return Ponteiro para a string.
 */
char* str_right_trim( char* str );

/**
 *  @brief  Retira caracteres em branco à esquerda e à direita da string.
 *  @param  str Ponteiro para a string.
 *  @return Ponteiro para a string.
 */
char* str_trim( char* str );

/**
 *  @brief  Duplica a string.
 *  @param  str Ponteiro para a string.
 *  @return Ponteiro para a string duplicada.
 */
char* str_duplicate( const char *str );

/**
 *  @brief  Substitui um caractere por outro na string.
 *  @param  str Ponteiro para a string.
 *  @param  oldchr Caractere a ser substituído.
 *  @param  newchr Caractere substituto.
 *  @return Ponteiro para a string.
 */
char* str_replace_char( char *str, const char oldchr, const char newchr );

/**
 *  @brief  Verifica se a string contém a substring.
 *  @param  str Ponteiro para a string.
 *  @param  src Ponteiro para a substring.
 *  @return Verdadeiro se a string contém a substring, falso caso contrário.
 */
bool str_contains(const char* str, const char* src);

/**
 *  @brief  Compara duas strings.
 *  @param  str1 Ponteiro para a primeira string.
 *  @param  str2 Ponteiro para a segunda string.
 *  @return 0 se as strings são iguais, 1 se str1 > str2, -1 se str1 < str2.
 */
bool str_equals( const char *str1, const char *str2 );

// --------------------------- Definitions

size_t str_len( const char *str )
{
    size_t len = 0;

    if( str )
    {
        while( *str ) { len = len + 1; str = str + 1; }
    } // end if
    return ( len );

} // end str_len ( )

char* str_copy( char *dst, const char* src )
{
    char *ret = NULL;
    
    if( dst && src )
    {
        ret = strcpy( dst, src );
    } // end if

    return ( ret );
} // end str_copy ( )

char* str_concat( const char *str1, const char *str2 )
{
    char *dst = NULL;

    if( str1 && str2 )
    {
        dst = (char*) malloc( (str_len(str1) + str_len(str2) + 1) * sizeof(char) );
        if( dst )
        {
            size_t var1 = 0;
            size_t var2 = 0;
            while( *(str1+var1) ) 
            { 
                *(dst+var1) = *(str1+var1); 
                var1 = var1 + 1; 
            } // end while
            while( *(str2+var2) ) 
            { 
                *(dst+var1+var2) = *(str2+var2); 
                var2 = var2 + 1; 
            } // end while
            *(dst+var1+var2) = '\0';
        } // end if
    } // end if

    return ( dst );
} // end str_concat ( )

int str_compare( const char* str1, const char* str2 )
{
    int ret = 0;

    if( !str1 || !str2 ) 
    {
        ret = ( str1 == str2 ) ? 0 : ( str1 ? 1 : -1 );
    }
    else
    {
        while( *str1 && *str2 && *str1 == *str2 ) 
        { 
            str1 = str1 + 1; 
            str2 = str2 + 1;
        } // end while
        ret = *str1 - *str2;
    } // end if

    return ( ret );
} // end str_compare ( )

char* str_char( const char* str, const int chr )
{
    char* ret = NULL;

    if( str )
    {
        while( *str && *str != chr ) 
        { 
            str = str + 1; 
        } // end while
        if( *str == chr ) 
        {
            ret = (char*)str;
        } // end if
    } // end if

    return ( ret );
} // end str_char ( )

size_t str_first_index_of( const char *str, const char chr )
{
    size_t val = -1;

    if( str )
    {
        size_t var = 0;
        while( *str != chr ) 
        { 
            str = str + 1; 
            var = var + 1;
        } // end while

        if( *str == chr ) 
        {
            val = var;
        } // end if
    } // end if

    return ( val );
} // end str_first_index_of ( )

size_t str_last_index_of( const char *str, const char chr )
{
    size_t val = -1;

    if( str )
    {
        size_t len = str_len( str );
        size_t var = len - 1;
        while( *(str+var) != chr ) 
        { 
            var = var - 1; 
        } // end while

        if( *(str+var) == chr ) {
            val = var;
        } // end if
    } // end if

    return ( val );
} // end str_last_index_of ( )

char* str_substring( const char *str, size_t start, size_t end )
{
    char *sub = NULL;

    if( str )
    {
        size_t len = str_len( str );
        if ( start < len && end < len  && start < end )
        {
            sub = (char*) malloc( (end - start + 1) * sizeof(char) );
            if( sub )
            {
                size_t var = 0;
                while( start <= end && *(str+start) != '\0' ) 
                { 
                    *(sub+var) = *(str+start); 
                    start = start + 1;
                    var = var + 1; 
                } // end while
                *(sub+var) = '\0';
            } // end if
        } // end if
    } // end if

    return ( sub );
} // end str_substring ( )

char** str_split( char* str, const char delimiter ) 
{
    char** sequence = NULL;
    size_t size = 0;

    if( str ) 
    {
        size_t lstr = str_len(str);

        // Contar a quantidade de delimitadores
        char* tmp = str;
        while( *tmp ) 
        {
            if( *tmp == delimiter ) 
            {
                size = size + 1;;
            } // end if
            tmp = tmp + 1;
        } // end while
        size = size + 1;; // Adicionar espaço NULL para terminação da Lista de Strings 

        sequence = (char**)malloc( size * sizeof(char*) );

        if( sequence ) 
        {
            size_t var = 0;
            size_t start = 0;
            size_t end = 0;
            
            while( var < size ) 
            {
                // Avançar end até encontrar o delimitador ou o final da string
                while( end < lstr && *(str+end) != delimiter ) 
                {
                    end = end + 1;
                } // end while

                // Criar substring para o intervalo [start, end]
                *(sequence+var) = str_substring( str, start, end-1 );

                // Se a substring for NULL, então atribuir uma string vazia
                if ( *(sequence+var) == NULL ) 
                {
                    *(sequence+var) = "";
                } // end if

                // Atualizar start e end para a próxima substring
                end = end + 1;
                start = end;
                var = var + 1;
            } // end while

            *(sequence+var) = NULL; // Terminar a lista com NULL
        } // end if
    } // end if

    return ( sequence );
} // end str_split ( )

char* str_left_trim( char* str )
{
    if( str )
    {
        size_t count = 0;
        while(  *(str+count) == ' '  || *(str+count) == '\t' || 
                *(str+count) == '\n' || *(str+count) == '\r' ) 
        { 
            count = count + 1; 
        } // end while
        
        if( count != 0 )
        {
            size_t var = 0;
            while( *(str+count+var) != '\0' ) 
            { 
                *(str+var) = *(str+count+var); 
                var = var + 1; 
            } // end while
            *(str+var) = '\0';
        } // end if
    } // end if

    return ( str );
} // end str_left_trim ( )

char* str_right_trim( char* str )
{
    if( str )
    {
        size_t len = str_len( str ) - 1;
        char* end = str + len;
        while( end >= str && ( *end == ' ' || *end == '\t' || *end == '\n' || *end == '\r' ) ) 
        { 
            *end = '\0'; 
            end = end - 1; 
        } // end while
        len = end - str + 1;
        *(str+len) = '\0';
    } // end if

    return ( str );
} // end str_right_trim ( )

char* str_trim( char* str )
{
    if( str )
    {
        str_left_trim( str );
        str_right_trim( str );
    } // end if
    return ( str );
} // end str_trim ( )

char* str_duplicate( const char *str )
{
    char *dup = NULL;
    size_t var = 0;
    if( str )
    {
        dup = (char*) malloc( str_len(str)+1 * sizeof(char) );
        if( dup )
        {
            while( *(str+var) ) { *(dup+var) = *(str+var); var = var + 1; }
            *(dup+var) = '\0';
        } // end if
    } // end if
    return ( dup );
} // end str_duplicate ( )

char* str_replace_char( char *str, const char oldchr, const char newchr )
{
    if( str )
    {
        size_t var = 0;
        while( *(str+var) )
        {
            if( *(str+var) == oldchr ) 
            {
                *(str+var) = newchr;
            } // end if
            var = var + 1;
        } // end while
    } // end if

    return ( str );
} // end str_replace_char ( )

bool str_contains(const char* str, const char* src)
{
    bool val = false;

    if( !str || !src ) 
    {
        val = false;
    } 
    else 
    {
        size_t lstr = str_len(str);
        size_t _Len_Src = str_len(src);

        for( size_t i = 0; i <= lstr - _Len_Src; ++i ) 
        {
            bool found = true;
            for( size_t j = 0; j < _Len_Src; ++j ) 
            {
                if( str[i + j] != src[j] ) 
                {
                    found = false;
                    j = _Len_Src;
                } // end if
            } // end for

            if( found ) 
            {
                val = true;
                i = lstr - _Len_Src + 1;
            } // end if
        } // end for
    } // end if

    return ( val );
} // end str_contains ( )

bool str_equals( const char *str1, const char *str2 )
{
    bool val = false;

    if( str1 && str2 )
    {
        val = true;
        size_t _Len1 = str_len(str1);
        size_t _Len2 = str_len(str2);
        
        if( _Len1 == _Len2 )
        {
            size_t var = 0;
            while( var < _Len1 ) 
            { 
                if( *(str1+var) != *(str2+var) ) 
                {
                    val = false;
                    var = _Len1;
                } // end if
                var = var + 1; 
            } // end while
        } // end if
    } // end if
    
    return ( val );
} // end str_equals ( )

#endif // __STR_H__
