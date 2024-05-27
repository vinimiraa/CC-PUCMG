#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Celula  */
typedef struct s_Celula
{
    int elemento;
    struct s_Celula* prox;
} Celula;

Celula* new_Celula( int elemento )
{
    Celula* nova = (Celula*) malloc( sizeof(Celula) );
    nova->elemento = elemento;
    nova->prox = NULL;
    return ( nova );
} // end new_Celula ( )

/* Pilha */
Celula* topo = NULL;

void push( int valor )
{
    Celula* temp = new_Celula( valor );
    temp->prox = topo;
    topo = temp;
    temp = NULL;
} // end push ( )

int pop( )
{
    int valor;
    if( topo == NULL ) {
        printf( "EMPTY" );
    }
    else
    {
        Celula* temp = topo;
        valor = temp->elemento;
        topo = temp->prox;
        temp->prox = NULL;
        free( temp );
        temp = NULL;
    } // end if
    return ( valor );
} // end pop ( )

int min ( )
{
    int menor = topo->elemento;
    for( Celula* temp = topo->prox; temp != NULL; temp = temp->prox )
    {
        if( temp->elemento < menor ){
            menor = temp->elemento;
        } // end if
    } // end for
    return ( menor );
} // end min ( )

void print ( )
{
    printf( "{" );
    for( Celula* temp = topo; temp != NULL; temp = temp->prox )
    {
        printf( " (%d) ", temp->elemento );
    }
    printf( "}\n" );
} // end print ( )

/* Funcao Principal */
int main ( void )
{
    int N = 0;
    char operacao[5] = { 0 };
    int V = 0;

    do {
        scanf( "%d", &N );  getchar( );
    } while ( N < 1 && 106 < N );
    
    for (int i = 0; i < N; i++)
    {
        scanf( "%s", operacao ); getchar( );
        if ( toupper(operacao[1]) == 'U') {
            do {
                scanf( "%d", &V ); getchar( );
            } while (V < 1 && 106 < V);            
            push( V );
        } else if ( toupper(operacao[1]) == 'O') {
            pop( );
        } else if ( toupper(operacao[1]) == 'I') {
            printf( "%d\n", min( ) );
        } else {
            printf( "\n%s\n", "ERRO: Operacao Invalida" );
        } // end if
        // print( );
    } // end for
    return ( 0 );
} // end main ( )
