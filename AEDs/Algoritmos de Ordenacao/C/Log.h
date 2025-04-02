#ifndef __LOG_H__
#define __LOG_H__

// ---------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------------------------- Struct - Log

typedef struct s_Log
{
    int     comparacoes;
    int     movimentacoes;
    int     subarranjos;
    clock_t inicioTempo;
    clock_t fimTempo;
    double  totalTempo;
} Log;

// ---------------------------- Protótipos - Log

Log* new_Log( void );
void delete_Log( Log* log );
void incrementarComparacoes ( Log* log, int quantidade );
void incrementarMovimentacoes ( Log* log, int quantidade ) ;
void incrementarSubarranjos ( Log* log, int quantidade ) ;
void inicioTempo ( Log* log );
void fimTempo ( Log* log );
void registrar ( Log* log );

// ---------------------------- Definições - Log

Log* new_Log( void )
{
    Log* log = (Log*) malloc ( sizeof(Log) );
    if( log != NULL )
    {
        log->comparacoes = 0;
        log->movimentacoes = 0;
        log->subarranjos = 0;
        log->inicioTempo = 0;
        log->fimTempo = 0;
        log->totalTempo = 0.0;
    } // end if
    return ( log );
} // end new_Log ( )

void delete_Log( Log* log ) {
    if( log != NULL ) {
        free( log ); 
        log = NULL;
    } // end if
} // end delete_Log ( )

void incrementarComparacoes ( Log* log, int quantidade ) 
{
    if( log != NULL ) {
        log->comparacoes += quantidade;
    } // end if
} // end incrementarComparacoes ( )

void incrementarMovimentacoes ( Log* log, int quantidade ) 
{
    if( log != NULL ) {
        log->movimentacoes += quantidade;
    } // end if
} // end incrementarMovimentacoes ( )

void incrementarSubarranjos ( Log* log, int quantidade ) 
{
    if( log != NULL ) {
        log->subarranjos += quantidade;
    } // end if
} // end incrementarSubarranjos ( )

void inicioTempo ( Log* log )
{
    if( log != NULL ) {
        log->inicioTempo = clock( );
    } // end if
} // end inicioTempo ( )

void fimTempo ( Log* log )
{
    if( log != NULL ) {
        log->fimTempo = clock( );
    } // end if
} // end fimTempo ( )

double calcularTempo ( Log* log )
{
    double result = 0.0;
    if( log != NULL )
    {
        result = (double)(log->fimTempo - log->inicioTempo) / CLOCKS_PER_SEC;
        log->totalTempo = result;
    } // end if
    return ( result );
} // end calcularTempo ( )

void registrar ( Log* log )
{
    printf( "\n%s\n\n" , "//----- ANALISE DO ALGORITMO -----//");
    printf( "Tempo de Execucao             : %lf s\n", calcularTempo( log ) );
    printf( "Numero de comparacoes         : %d   \n", log->comparacoes     );
    printf( "Numero de movimentacoes       : %d   \n", log->movimentacoes   );
    printf( "Numero de subarranjos criados : %d   \n", log->subarranjos     );
    printf( "\n%s\n"   , "//---------- FIM ANALISE ---------//");
} // end registrar ( )

#endif