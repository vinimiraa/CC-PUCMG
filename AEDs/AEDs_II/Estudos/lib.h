#ifndef __LIB_H__
#define __LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len ( const char *_Str )
{
    int _Len = 0;
    while( *(_Str+_Len) ) { _Len = _Len + 1; }
    return ( _Len );
}

char* str_copy( char *_Dest, const char *_Str )
{
    size_t _Len = str_len( _Str );
    _Dest = (char*)malloc( _Len * sizeof(char) );
    size_t _Var = 0;
    while( *(_Str+_Var) ) { *(_Dest+_Var) = *(_Str+_Var); _Var = _Var + 1; }
    *(_Dest+_Var) = '\0';
    return ( _Dest );
}

char* str_dup ( const char *_Str )
{
    char *_Dup = NULL;
    size_t _Var = 0;
    if( _Str )
    {
        _Dup = (char*)malloc( str_len(_Str)+1 * sizeof(char) );
        while( *(_Str+_Var) ) { *(_Dup+_Var) = *(_Str+_Var); _Var = _Var + 1; }
        *(_Dup+_Var) = '\0';
    }
    return ( _Dup );
}

char* str_concat ( const char *_Str1, const char *_Str2 )
{
    char *_Dest = (char*)malloc( (str_len(_Str1) + str_len(_Str2)+1) * sizeof(char) );
    size_t _Var1 = 0;
    size_t _Var2 = 0;
    while( *(_Str1+_Var1) ) { *(_Dest+_Var1) = *(_Str1+_Var1); _Var1 = _Var1 + 1; }
    while( *(_Str2+_Var2) ) { *(_Dest+_Var1+_Var2) = *(_Str2+_Var2); _Var2 = _Var2 + 1; }
    *(_Dest+_Var1) = '\0';
    return ( _Dest );
}

char* str_substring ( const char *_Str, size_t _Start, size_t _End )
{
    size_t _Len_Str = str_len( _Str );
    char *_Sub = NULL;
    if( _Start >= _Len_Str && _End >= _Len_Str  && _Start > _End )
    {
        return ( NULL );
    }
    else
    {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*)malloc( (_Len+1) * sizeof(char) );
        size_t j = 0;
        for( size_t i = _Start; i <= _End; i = i + 1, j = j + 1 )
        {
            *(_Sub+j) = *(_Str+i);
        }
        *(_Sub+j) = '\0';
    }
    return ( _Sub );
}

char** str_split( const char *_Str, const char *_Delimiter )
{
    char** _Sequence = NULL;
    size_t _Len_Str = str_len( _Str );
    size_t _Len_Del = str_len( _Delimiter );
    size_t _Size = 0;
    // Descobrir o tamanho do arranjo de apontadores
    for( size_t i = 0; i < _Len_Str; i = i + 1 )
    {
        if( strncmp( _Str+i, _Delimiter, _Len_Del ) == 0 )
        {
            _Size = _Size + 1;
        }
    }
    // Alocar o espaço do arranjo de apontadores
    _Sequence = (char**)malloc( (_Size-1) * sizeof(char*) );
    // Achar a substring até o delimitador e guardá-la no arranjo
    for( size_t i = 0, start = 0, end = 0; end < _Len_Str; end = end  + 1 )
    {
        if( strncmp( _Str+end, _Delimiter, _Len_Del ) == 0 )
        {
            *(_Sequence+i) = str_substring( _Str, start, end-1 );
            start = end + 1;
        }
    }
    return ( _Sequence );
}

#endif