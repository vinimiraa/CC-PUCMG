#include "lib.h"

int main( )
{
    char*  s0 = NULL;
    char*  s1 = "Vinicius Miranda Araujo";
    char*  s2 = ", Vulgo Show";
    char** s3 =  NULL;
    char*  s4 = "9e3f7ce4-b9a7-4244-b709-dae5c1f1d4a8;Harry Potter;['The Boy Who Lived', 'The Chosen One', 'Undesirable No. 1', 'Potty'];Gryffindor;half-blood;human;stag;FALSO;VERDADEIRO;Daniel Radcliffe;VERDADEIRO;[];31-07-1980;1980;green;male;black;VERDADEIRO";
    char*  s5 = "\r\t\n\t\r ABCDEFGH \n\r\t\n\r";

    printf ( "\n%s\n", "**** LIB TESTES ****" );

    printf( "\ns0 = %s\n\ns1 = %s\n\ns2 = %s\n\ns4 = %s\n\ns5 = %s\n", s0, s1, s2, s4, s5 );

    printf( "\nstr_len(s0) = %d\n", str_len(s0) );
    
    printf( "\nstr_dup(s1) = %s\n", str_dup(s1) ); 
    
    str_copy(s0,s1);
    printf( "\nstr_copy(s0,s1) = %s\n", s0 );

    printf( "\nstr_copy(s0,s1) = %s\n", str_copy(s0,s1) );
    
    printf( "\nstr_concat(s1,s2) = %s\n", str_concat(s1,s2) );
    
    printf( "\nstr_substring(s1,0,10) = %s\n", str_substring(s1, 0, 10) );

    printf( "\nstr_trim(s5) = %s\n", str_trim(s5) );

    printf( "\nstr_replace(s2,\'o\', \'0\') = %s\n", str_replace(s2, 'o', '0') );

    printf( "\nstr_replace_first(s2,\'o\', \'0\') = %s\n", str_replace_first(s2, 'o', '0') );

    printf( "\nstr_replace_last(s2,\'o\', \'0\') = %s\n", str_replace_last(s2, 'o', '0') );

    s3 = str_split( s4, ';' );
    printf( "\ns3 = str_split(s4) :\n" );
    int i = 0; while( *(s3+i) ) { i++; } 
    for( int x = 0; x < i; x++ ) { printf( " s3[%2d] = \"%s\"\n", x, s3[x] ); }

    printf ( "\n%s\n", "**** FIM TESTES ****" );

    return ( 0 );
}