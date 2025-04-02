#include <stdio.h>
#include <string.h>
#include "str.h"

void test_str_len( void )
{
    printf( "\n\n> TEST str_len\n\n" );

    char str[] = "Hello, World!";
    size_t len = str_len( str );
    printf( "str_len( \"%s\" ) = %lu\n", str, len );
} // end test_str_len( )

void test_str_copy( void )
{
    printf( "\n\n> TEST str_copy\n\n" );

    char str[] = "Hello, World!";
    char dst[ 20 ];
    printf( "str_copy( \"%s\", \"%s\" ) = \"%s\"\n", dst, str, str_copy( dst, str ) );
} // end test_str_copy( )

void test_str_concat( void )
{
    printf( "\n\n> TEST str_concat\n\n" );

    char str1[] = "Hello, ";
    char str2[] = "World!";
    printf( "str_concat( \"%s\", \"%s\" ) = \"%s\"\n", str1, str2, str_concat( str1, str2 ) );
} // end test_str_concat( )

void test_str_char( void )
{
    printf( "\n\n> TEST str_char\n\n" );

    char str[] = "Hello, World!";
    char chr = 'W';
    printf( "str_char( \"%s\", '%c' ) = \"%s\"\n", str, chr, str_char( str, chr ) );
} // end test_str_char( )

void test_str_compare( void )
{
    printf( "\n\n> TEST str_compare\n\n" );

    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    printf( "str_compare( \"%s\", \"%s\" ) = %d\n", str1, str2, str_compare( str1, str2 ) );
} // end test_str_compare( )

void test_str_first_index_of( void )
{
    printf( "\n\n> TEST str_first_index_of\n\n" );

    char str[] = "Hello, World!";
    char chr = 'o';
    printf( "str_first_index_of( \"%s\", '%c' ) = %lu\n", str, chr, str_first_index_of( str, chr ) );
} // end test_str_first_index_of( )

void test_str_last_index_of( void )
{
    printf( "\n\n> TEST str_last_index_of\n\n" );

    char str[] = "Hello, World!";
    char chr = 'o';
    printf( "str_last_index_of( \"%s\", '%c' ) = %lu\n", str, chr, str_last_index_of( str, chr ) );
} // end test_str_last_index_of( )

void test_str_substring( void )
{
    printf( "\n\n> TEST str_substring\n\n" );

    char str[] = "Hello, World!";
    size_t start = 7;
    size_t end = 11;
    printf( "str_substring( \"%s\", %lu, %lu ) = \"%s\"\n", str, start, end, str_substring( str, start, end ) );
} // end test_str_substring( )

void test_str_split( void )
{
    printf( "\n\n> TEST str_split\n\n" );

    char str[] = "Hello, World!";
    char delimiter = ' ';
    char** ret = str_split( str, delimiter );
    printf( "str_split( \"%s\", '%c' ) = [ ", str, delimiter );
    for( size_t i = 0; *(ret+i) != NULL; i++ )
    {
        printf( "\"%s\" ", *(ret+i) );
    } // end for
    printf( "]\n" );
} // end test_str_split( )

void test_str_left_trim( void )
{
    printf( "\n\n> TEST str_left_trim\n\n" );

    char str[] = "    Hello, World!";
    printf( "str_left_trim( \"%s\" ) = \"%s\"\n", str, str_left_trim( str ) );
} // end test_str_left_trim( )

void test_str_right_trim( void )
{
    printf( "\n\n> TEST str_right_trim\n\n" );

    char str[] = "Hello, World!    ";
    printf( "str_right_trim( \"%s\" ) = \"%s\"\n", str, str_right_trim( str ) );
} // end test_str_right_trim( )

void test_str_trim( void )
{
    printf( "\n\n> TEST str_trim\n\n" );

    char str[] = "    Hello, World!    ";
    printf( "str_trim( \"%s\" ) = \"%s\"\n", str, str_trim( str ) );
} // end test_str_trim( )

void test_str_duplicate( void )
{
    printf( "\n\n> TEST str_duplicate\n\n" );

    char str[] = "Hello, World!";
    printf( "str_duplicate( \"%s\" ) = \"%s\"\n", str, str_duplicate( str ) );
} // end test_str_duplicate( )

void test_str_replace_char( void )
{
    printf( "\n\n> TEST str_replace_char\n\n" );

    char str[] = "Hello, World!";
    char oldchr = 'o';
    char newchr = '0';
    printf( "str_replace_char( \"%s\", '%c', '%c' ) = \"%s\"\n", str, oldchr, newchr, str_replace_char( str, oldchr, newchr ) );
} // end test_str_replace_char( )

void test_str_contains( void )
{
    printf( "\n\n> TEST str_contains\n\n" );

    char str[] = "Hello, World!";
    char src[] = "World";
    bool ret = str_contains( str, src );
    printf( "str_contains( \"%s\", \"%s\" ) = %s\n", str, src, ret ? "true" : "false" );
} // end test_str_contains( )

void test_str_equals( void )
{
    printf( "\n\n> TEST str_equals\n\n" );

    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    bool ret = str_equals( str1, str2 );
    printf( "str_equals( \"%s\", \"%s\" ) = %s\n", str1, str2, ret ? "true" : "false" );
} // end test_str_equals( )

int main( void ) 
{
    test_str_len( );
    test_str_copy( );
    test_str_concat( );
    test_str_char( );
    test_str_compare( );
    test_str_first_index_of( );
    test_str_last_index_of( );
    test_str_substring( );
    test_str_split( );
    test_str_left_trim( );
    test_str_right_trim( );
    test_str_trim( );
    test_str_duplicate( );
    test_str_replace_char( );
    test_str_contains( );
    test_str_equals( );

    return ( 0 );
} // main()

