#include "lib.h"

int main( )
{
    char*  s0 = "oi";
    char*  s1 = "Vinicius;Miranda;Araujo";
    char*  s2 = "Vulgo Show";
    char** s3 =  NULL;

    printf( "s0 = %s\ns1 = %s\ns2 = %s\ns3 = %s\n", s0, s1, s2, s3);
    printf( "str_len(s1) = %d\n", str_len(s1) );
    printf( "str_dup(s1) = %s\n", str_dup(s1) );
    printf( "str_copy(s0,s1) = %s\n", str_copy(s0,s1) );
    printf( "str_concat(s1,s2) = %s\n", str_concat(s1,s2) );
    printf( "str_substring(s1,0,10) = %s\n", str_substring(s1, 0, 10) );
    s3 = str_split( s1, ";" );
    printf( "str_split : \n" );
    for( int x = 0; x < 5; x++ )
    {
        printf( "str[%d] = %s\n", x, s3[x] );
    }
    return ( 0 );
}
