#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Instrucoes
{
    char X;
    char Y;
    char *W;
} Instrucoes;

Instrucoes* new_Instrucoes(  )
{
	Instrucoes* instrucao = (Instrucoes*) malloc( sizeof(Instrucoes) );
	if( instrucao != NULL )
	{
		instrucao->X = '\0';
		instrucao->Y = '\0';
		instrucao->W = (char*) malloc ( sizeof(char) * 8 );
		if( instrucao->W != NULL ) {
			for( int i = 0; i < 8; i = i + 1 ) {
				instrucao->W[i] = '\0';
			} // for
		} // if
	} // if
	return ( instrucao );
} // end new_instrucoes ( )

void read_from_file( char* filepath )
{
	Instrucoes* instrucao = new_Instrucoes(  );
	FILE* file = fopen( filepath, "rt" );
	char _input[8];
	
	if( file == NULL ) {
		printf( "\n%s\n", "[ERRO] Unable to open file!" );
	} else {
		// ler cabecalho
		fscanf( file, "%s", &_input );
		
		if( strcmp( _input, "inicio:" ) != 0 ) {
			printf( "\n%s\n", "[ERRO] Start not found!" );
		} else {
			// ler instrucao
			fscanf( file, "%s", _input );
		
			// enquanto nao encontrar o fim
			while( strcmp( _input, "fim." ) != 0 ) {
				// verificar se a instrucao termina com ;
				int len = strlen( _input );
				if( _input[len-1] != ';' ) {
					printf( "\n%s\n", "[ERRO] Missing \';\'!" );
				} else {
					// verificar qual o tipo de instrucao
					if( _input[0] == 'X' ) {
						instrucao->X = _input[len-2];
					} else if( _input[0] == 'Y' ) {
						instrucao->Y = _input[len-2];
					} else if( _input[0] == 'W' ) {
						for( int i = 2; i < len-1; i++ ) {
							instrucao->W[i-2] = _input[i];
						} // for
					} // if
				} // if
				fscanf( file, "%s", _input );
			} // while
		} // if
	} // if
	fclose( file );
} // end read_from_file ( )

int main ( void )
{
	char* inputfile = "data.txt";
	char* outputfile = "";
	
	read_from_file( inputfile );
    
	return ( 0 );
} // end main ()