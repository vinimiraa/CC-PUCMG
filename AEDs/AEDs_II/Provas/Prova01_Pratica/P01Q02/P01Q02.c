#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Duende
{
    char nome[20];
    int  idade;
} Duende;

int main( int argc, char const *argv[] )
{
    int N;

    // ler a quantidade de duendes
    do
    {
        scanf( "%d", &N );
    } while ( (N < 0 && 100 < N) || (N % 3 != 0) );

    // criar um arranjo de duende, cada duende tem nome e idade
    Duende duende[N];

    // ler o nome e a idade dos duendes
    for( int x = 0; x < N; x = x + 1 )
    {
        do
        {
            scanf( "%s %d", duende[x].nome, &duende[x].idade ); getchar();
        } while ( (strlen(duende[x].nome) > 20) || (duende[x].idade < 10 && 100 < duende[x].idade) );
    } // end for

    // mostrar os times
    for( int x = 0, t = 1; x < N; x = x + 3, t++ )
    {
        printf( "Time %d\n", t );
        printf( "%s %d\n", duende[x].nome, duende[x].idade );
        printf( "%s %d\n", duende[x+1].nome, duende[x+1].idade );
        printf( "%s %d\n", duende[x+2].nome, duende[x+2].idade );
    } // end for
    

    return 0;
} // end main ( )
