#ifndef __CSTRING_H__
#define __CSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

void flush( void )
{
    int x = 0;
    do {
        x = getchar( );
    } while ( x != EOF && x != '\n' );
    clearerr(stdin); // reiniciar o estado de EOF
} // end flush ( )

char* str_read ( size_t _Size ) 
{
    char *_Str = (char*) malloc( _Size * sizeof(char) );
    if( _Str != NULL && fgets( _Str, _Size, stdin ) != NULL )
    {
        _Str[strcspn(_Str, "\n")] = '\0';
        _Str[strcspn(_Str, "\r")] = '\0';
        flush( );
    } // end if
    return ( _Str ); 
} // end str_read ( )

int str_len ( const char *_Str )
{
    int _Len = -1;
    if( _Str )
    {
        _Len = 0;
        while( *(_Str+_Len) ) { _Len = _Len + 1; }
    } // end if
    return ( _Len );
} // end str_len ( )

char str_charAt ( const char *_Str, const int _Index )
{
    char _Val = 0;
    if( _Str && 0 <= _Index && _Index < str_len(_Str) ) {
        _Val = *(_Str+_Index);
    } // end if
    return ( _Val );
} // end str_charAt ( )

int str_indexOf ( const char *_Str, const char _Char )
{
    size_t _Val = -1;
    if( _Str )
    {
        size_t _Var = 0; 
        while( *(_Str+_Var) != _Char ) { _Var = _Var + 1; }
        if( *(_Str+_Var) == _Char ) {
            _Val = _Var;
        } // end if
    }
    return ( _Val );
} // end str_indexOf ( )

int str_lastIndexOf ( const char *_Str, const char _Char )
{
    int _Val = -1;
    if( _Str )
    {
        size_t _Var = str_len(_Str)-1; 
        while( *(_Str+_Var) != _Char ) { _Var = _Var - 1; }
        if( *(_Str+_Var) == _Char ) {
            _Val = _Var;
        } // end if
    }
    return ( _Val );
} // end str_indexOf ( )

char* str_concat ( const char *_Str1, const char *_Str2 )
{
    char *_Dest = NULL;
    if( _Str1 && _Str2 )
    {
        _Dest = (char*) malloc( (str_len(_Str1) + str_len(_Str2) + 1) * sizeof(char) );
        if( _Dest )
        {
            size_t _Var1 = 0;
            size_t _Var2 = 0;
            while( *(_Str1+_Var1) ) { *(_Dest+_Var1) = *(_Str1+_Var1); _Var1 = _Var1 + 1; }
            while( *(_Str2+_Var2) ) { *(_Dest+_Var1+_Var2) = *(_Str2+_Var2); _Var2 = _Var2 + 1; }
            *(_Dest+_Var1+_Var2) = '\0';
        } // end if
    } // end if
    return ( _Dest );
} // end str_concat ( )

char* str_substring ( const char *_Str, size_t _Start, size_t _End )
{
    char *_Sub = NULL;
    size_t _Len_Str = str_len( _Str );
    if ( _Start < _Len_Str && _End < _Len_Str  && _Start <= _End )
    {
        size_t _Len = _End - _Start + 1;
        _Sub = (char*) malloc( (_Len+1) * sizeof(char) );
        if( _Sub )
        {
            size_t j = 0;
            for ( size_t i = _Start; i <= _End; i = i + 1, j = j + 1 ) {
                *(_Sub+j) = *(_Str+i);
            } // end for
            *(_Sub+j) = '\0';
        } // end if
    } // end if
    return ( _Sub );
} // end str_substring ( )

char* str_trim ( char *_Str )
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
    } // end if
    return ( _Dest );
} // end str_ trim( )

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
            if ( *_Temp == _Delimiter ) {
                _Size = _Size + 1;
            } // end if
            _Temp = _Temp + 1;
        } // end while
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
                } // end if
                _Start = _End + 1; 
                _End = _Start;
                _Var++;
            } // end while
            *(_Sequence+_Var) = NULL;
        } // end if
    } // end if
    return ( _Sequence );
} // end str_split ( )

char* str_dup ( const char *_Str )
{
    char *_Dup = NULL;
    size_t _Var = 0;
    if( _Str )
    {
        _Dup = (char*) malloc( str_len(_Str)+1 * sizeof(char) );
        if( _Dup )
        {
            while( *(_Str+_Var) ) { *(_Dup+_Var) = *(_Str+_Var); _Var = _Var + 1; }
            *(_Dup+_Var) = '\0';
        } // end if
    } // end if
    return ( _Dup );
} // end str_dup ( )

char* str_replace_c ( const char *_Str, const char _OldChar, const char _NewChar )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = 0;
        while( *(_Dest+_Var) )
        {
            if( *(_Dest+_Var) == _OldChar ) {
                *(_Dest+_Var) = _NewChar;
            } // end if
            _Var = _Var + 1;
        } // end while
    } // end if
    return ( _Dest );
} // end str_replace_c ( )

char* str_replace_c_first ( const char *_Str, const char _OldChar, const char _NewChar )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = 0;
        while( *(_Dest+_Var) != _OldChar ) { _Var = _Var + 1; }
        *(_Dest+_Var) = _NewChar;
    } // end if
    return ( _Dest );
} // end str_replace_c_first ( )

char* str_replace_c_last ( const char *_Str, const char _OldChar, const char _NewChar )
{
    char* _Dest = NULL;
    if( _Str )
    {
        _Dest = str_dup(_Str);
        size_t _Var = str_len(_Dest);
        while( *(_Dest+_Var) != _OldChar ) { _Var = _Var - 1; }
        *(_Dest+_Var) = _NewChar;
    } // end if
    return ( _Dest );
} // end str_replace_c_last ( )

bool str_contains (const char* _Str, const char* _Src)
{
    bool _Val = false;
    if( !_Str || !_Src ) {
        _Val = false;
    } 
    else 
    {
        size_t _Len_Str = str_len(_Str);
        size_t _Len_Src = str_len(_Src);

        for( size_t i = 0; i <= _Len_Str - _Len_Src; ++i ) 
        {
            bool found = true;
            for( size_t j = 0; j < _Len_Src; ++j ) 
            {
                if( _Str[i + j] != _Src[j] ) 
                {
                    found = false;
                    j = _Len_Src;
                } // end if
            } // end for
            if( found ) {
                _Val = true;
                i = _Len_Str - _Len_Src + 1;
            } // end if
        } // end for
    } // end if
    return ( _Val );
} // end str_contains ( )

bool str_equals ( const char *_Str1, const char *_Str2 )
{
    bool _Val = false;
    if( _Str1 && _Str2 )
    {
        _Val = true;
        size_t _Len1 = str_len(_Str1);
        size_t _Len2 = str_len(_Str2);
        if( _Len1 == _Len2 )
        {
            size_t _Var = 0;
            while( _Var < _Len1 ) 
            { 
                if( *(_Str1+_Var) != *(_Str2+_Var) ) 
                {
                    _Val = false;
                    _Var = _Len1;
                } // end if
                _Var = _Var + 1; 
            } // end while
        } // end if
    } // end if
    return ( _Val );
} // end str_equals ( )

#endif // __CSTRING_H__