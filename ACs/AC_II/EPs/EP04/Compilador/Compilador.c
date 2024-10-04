#include "Lib.h"

/**
 * 	Árvore de Sintaxe Abstrata
 * 	
 *          <Exp>
 *        /   |   \
 *       |    |    |
 * 	( <Fator> | <Fator> )
 *  
 * 	<Exp>   ::= <Fator> & <Fator>
 * 	
 * 	<Fator> ::= X | Y | W 
 *            | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F
 * 			  | umL | AonB | copiaA | nAxnB | AeBn | nA | AenB 
 *            | nAonB | AxB | zeroL | copiaB | AeB | nB | nAeBn | AoB | nAeB
 * 	
 * 	<Comando> ::= <Fator> <Operador> <Fator> <Terminador>
 */

void read_write_file( char* in_filepath, char* out_filepath )
{
	char X = '\0';   // X -> Primeira variável
	char Y = '\0';   // Y -> Segunda variável
	char W[8];       // W -> Operação
	char _input[8];  // _input -> Linha a ser lida
	FILE* finput  = fopen( in_filepath, "rt"  );  // finput -> Arquivo de entrada
	FILE* foutput = fopen( out_filepath, "wt" );  // foutput -> Arquivo de saída
	
	// verificar se o arquivo de entrada existe
	if( finput == NULL ) {
		printf( "\n%s\n", "[ERRO] Unable to open input file!" );
	} 
	else 
	{
		// ler comando incial
		fscanf( finput, "%s", _input );
		
		// verificar se e' o comando 'inicio:'
		if( is_start( _input ) == false ) {
			printf( "\n%s\n", "[ERRO] Start not found!" );
		} 
		else 
		{
			// ler linha de comando
			fscanf( finput, "%s", _input );
		
			// enquanto nao encontrar o comando 'fim.'
			while( is_end( _input ) == false ) 
			{
				// verificar se e' um comando valido
				if( is_command( _input ) == true ) 
				{
					// pegar o valor de cada atribuicao
					int len = strlen( _input );
					if( _input[0] == 'X' ) {
						X = _input[len-2];
					} else if( _input[0] == 'Y' ) {
						Y = _input[len-2];
					} else if( _input[0] == 'W' ) {
						strncpy(W, &_input[2], len - 3);
						W[len-3] = '\0';
						char exp = find_instruction( W );
						fprintf( foutput, "%c%c%c\n", X, exp, Y );
					} // if
				} // if
				fscanf( finput, "%s", _input );
			} // while
		} // if
	} // if
	fclose( finput );
	fclose( foutput );
} // end read_from_file ( )

int main ( void )
{
	char* inputfile = "data.txt";
	char* outputfile = "ALU.hex";
	
	read_write_file( inputfile, outputfile );
    
	return ( 0 );
} // end main ( )
