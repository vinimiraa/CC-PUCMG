#include <stdio.h>
#include <stdlib.h>

/* Celula */
typedef struct s_Celula
{
    int H;
    int M;
    int C;
    struct s_celula* prox; 
} Celula;

Celula* new_Celula( int H, int M, int C )
{
    Celula* nova = (Celula*) malloc( sizeof(Celula) );
    nova->H = H;
    nova->M = M;
    nova->C = C;
    nova->prox = NULL;
    return( nova );
}

/* Fila */
Celula* primeiro = NULL;
Celula* ultimo = NULL;

void start ( )
{
    primeiro = new_Celula( 0,0,0 );
    ultimo = primeiro;
}

void inserir( int H, int M, int C )
{
    ultimo->prox = new_Celula( H, M, C );
    ultimo = ultimo->prox;
}

/*
 * Funcao principal
 */
int main ( void )
{
    start( );
    int N = 0;
    int H = 0;
    int M = 0;
    int C = 0;
    int critico = 0;
    do
    {
        scanf( "%d", &N );
    } while (N < 0 && 25 < N);

    for (int i = 0; i < N; i++)
    {
        do
        {
            scanf( "%d %d %d", &H, &M, &C );
        } while ((H < 7 && 19 < H) && (M < 0 && 60 < M));
        inserir( H, M, C );
    }
    printf( "%d\n", critico );

    do
    {
        scanf( "%d", &N );
    } while (N < 0 && 25 < N);

    for (int i = 0; i < N; i++)
    {
        do
        {
            scanf( "%d %d %d", &H, &M, &C );
        } while ((H < 7 && 19 < H) && (M < 0 && 60 < M));
        inserir( H, M, C );
    }
    printf( "%d\n", critico );

    return ( 0 );
} // end main ( )