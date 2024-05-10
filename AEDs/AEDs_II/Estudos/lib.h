#ifndef __LIB_H__
#define __LIB_H__

// --------------------------- Libs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------- Prototypes

char*  str_read          ( size_t _Size );
int    str_len           ( const char *_Str );
char*  str_copy          ( char *_Dest, const char *_Str );
char*  str_dup           ( const char *_Str );
char*  str_concat        ( const char *_Str1, const char *_Str2 );
char*  str_substring     ( const char *_Str, size_t _Start, size_t _End );
char*  str_trim          ( const char *_Str );
char** str_split         ( char *_Str, const char _Delimiter );
char*  str_replace       ( const char *_Str, const char _Old, const char _New );
char*  str_replace_first ( const char *_Str, const char _Old, const char _New );
char*  str_replace_last  ( const char *_Str, const char _Old, const char _New );

// --------------------------- Definitions

char* str_read ( size_t _Size ) 
{
    char *_Str = (char*) malloc( _Size * sizeof(char) );
    if( _Str != NULL )
    {
        fgets( _Str, _Size, stdin );
        _Str[strcspn(_Str,'\n')] = '\0';
        _Str[strcspn(_Str,'\r')] = '\0';
    } // end if
    return ( _Str ); 
} 

int str_len ( const char *_Str )
{
    int _Len = -1;
    if( _Str )
    {
        _Len = 0;
        while( *(_Str+_Len) ) { _Len = _Len + 1; }
    }
    return ( _Len );
} 

char* str_copy( char *_Dest, const char *_Str )
{
    char *_Temp = _Dest; 
    size_t _Len = str_len( _Str );
    _Temp = (char*) realloc( _Temp, (_Len + 1) * sizeof(char) );
    _Dest = _Temp;
    // printf( "temp == NULL %d\n", _Temp == NULL );
    size_t _Var = 0;
    while ( *(_Str+_Var) ) { *(_Temp+_Var) = *(_Str+_Var); _Var = _Var + 1; }
    *(_Temp+_Var) = '\0';
    // printf( "dest = %s, temp = %s\n", _Dest, _Temp );
    return ( _Temp );
}

char* str_dup ( const char *_Str )
{
    char *_Dup = NULL;
    size_t _Var = 0;
    if( _Str )
    {
        _Dup = (char*) malloc( str_len(_Str)+1 * sizeof(char) );
        while( *(_Str+_Var) ) { *(_Dup+_Var) = *(_Str+_Var); _Var = _Var + 1; }
        *(_Dup+_Var) = '\0';
    }
    return ( _Dup );
}

char* str_concat ( const char *_Str1, const char *_Str2 )
{
    char *_Dest = (char*) malloc( (str_len(_Str1) + str_len(_Str2) + 1) * sizeof(char) );
    size_t _Var1 = 0;
    size_t _Var2 = 0;
    while( *(_Str1+_Var1) ) { *(_Dest+_Var1) = *(_Str1+_Var1); _Var1 = _Var1 + 1; }
    while( *(_Str2+_Var2) ) { *(_Dest+_Var1+_Var2) = *(_Str2+_Var2); _Var2 = _Var2 + 1; }
    *(_Dest+_Var1+_Var2) = '\0';
    return ( _Dest );
}

char* str_substring ( const char *_Str, size_t _Start, size_t _End )
{
    char *_Sub = NULL;
    size_t _Len_Str = str_len( _Str );
    if ( _Start < _Len_Str && _End < _Len_Str  && _Start <= _End )
    {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*) malloc( (_Len+1) * sizeof(char) );
        size_t j = 0;
        for ( size_t i = _Start; i <= _End; i = i + 1, j = j + 1 )
        {
            *(_Sub+j) = *(_Str+i);
        }
        *(_Sub+j) = '\0';
    }
    return ( _Sub );
}

char* str_trim ( const char *_Str )
{
    char *_Dest = NULL;
    if ( _Str )
    {
        size_t _Len   = str_len(_Str);
        size_t _Start = 0;
        size_t _End   = _Len-1;
        while ( _Start < _End && ( *(_Str+_Start) == ' ' || *(_Str+_Start) == '\n' || *(_Str+_Start) == '\r' || *(_Str+_Start) == '\t' ) ) 
        { _Start = _Start + 1; }
        while ( _End > _Start && ( *(_Str+_End) == ' ' || *(_Str+_End) == '\n' || *(_Str+_End) == '\r' || *(_Str+_End) == '\t' ) ) 
        { _End = _End - 1; }
        _Dest = str_substring( _Str, _Start, _End );
    }
    return ( _Dest );
}

char** str_split( char *_Str, const char _Delimiter )
{
    char** _Sequence = NULL;
    size_t _Size = 0;
    if( _Str )
    {
        size_t _Len_Str = str_len( _Str );
        // Contar a quantidade de delimitadores
        char *_Temp = _Str;
        while ( *_Temp )
        {
            if (  *_Temp == _Delimiter ) {
                _Size = _Size + 1;
            }
            _Temp = _Temp + 1;
        }
        _Size = _Size + 1; // Adicionar espaço NULL para terminação da Lista de Strings 

        _Sequence = (char**) malloc( _Size * sizeof(char*) );

        if ( _Sequence )
        {
            size_t _Var   = 0;
            size_t _Start = 0;
            size_t _End   = 0;
            while ( _Var < _Size )
            {
                while ( _End < _Len_Str && *(_Str+_End) != _Delimiter ) { _End++; }
                *(_Sequence+_Var) = str_substring( _Str, _Start, _End-1 );
                if ( *(_Sequence+_Var) == NULL ) {
                    *(_Sequence+_Var) = "";
                }
                _Start = _End + 1; 
                _End = _Start;
                _Var++;
            }
            *(_Sequence+_Var) = NULL;
        }
    }
    return ( _Sequence );
}

char* str_replace ( const char *_Str, const char _Old, const char _New )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = 0;
        while( *(_Dest+_Var) )
        {
            if( *(_Dest+_Var) == _Old )
            {
                *(_Dest+_Var) = _New;
            }
            _Var = _Var + 1;
        }
    }
    return ( _Dest );
}

char* str_replace_first ( const char *_Str, const char _Old, const char _New )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = 0;
        while( *(_Dest+_Var) != _Old ) { _Var = _Var + 1; }
        *(_Dest+_Var) = _New;
    }
    return ( _Dest );
}

char* str_replace_last ( const char *_Str, const char _Old, const char _New )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = str_len(_Dest);
        while( *(_Dest+_Var) != _Old ) { _Var = _Var - 1; }
        *(_Dest+_Var) = _New;
    }
    return ( _Dest );
}

#endif