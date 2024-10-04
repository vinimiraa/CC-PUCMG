#ifndef __EP04_H__
#define __EP04_H__

#include "cstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_start( char* input )
{
	return ( strcmp(input, "inicio:") == 0);
} // end is_start ( )

bool is_end( char* input )
{
	return ( strcmp(input, "fim." ) == 0 );
} // end is_end ( )

char find_instruction( char* input )
{
	char res = 0;
	if( strcmp(input, "umL") == 0 ) {
		res = '0';
	} else if( strcmp(input, "AonB") == 0 ) {
		res = '1';
	} else if( strcmp(input, "copiaA") == 0 ) {
		res = '2';
	} else if( strcmp(input, "nAxnB") == 0 ) {
		res = '3';
	} else if( strcmp(input, "AeBn") == 0 ) {
		res = '4';
	} else if( strcmp(input, "nA") == 0 ) {
		res = '5';
	} else if( strcmp(input, "AenB") == 0 ) {
		res = '6';
	} else if( strcmp(input, "nAonB") == 0 ) {
		res = '7';
	} else if( strcmp(input, "AxB") == 0 ) {
		res = '8';
	} else if( strcmp(input, "zeroL") == 0 ) {
		res = '9';
	} else if( strcmp(input, "copiaB") == 0 ) {
		res = 'A';
	} else if( strcmp(input, "AeB") == 0 ) {
		res = 'B';
	} else if( strcmp(input, "nB") == 0 ) {
		res = 'C';
	} else if( strcmp(input, "nAeBn") == 0 ) {
		res = 'D';
	} else if( strcmp(input, "AoB") == 0 ) {
		res = 'E';
	} else if( strcmp(input, "nAeB") == 0 ) {
		res = 'F';
	} else {
		printf( "\n[ERRO] Instruction \'%s\' not found!\n", input );
	} // if
	return ( res );
} // end find_instruction ( )

bool is_factor( char* input ) 
{
	bool res = false;
	if(    strcmp(input, "X"     ) == 0 || strcmp(input, "Y"     ) == 0 || strcmp(input, "W"     ) == 0 
		|| strcmp(input, "0"     ) == 0 || strcmp(input, "1"     ) == 0 || strcmp(input, "2"     ) == 0
		|| strcmp(input, "3"     ) == 0 || strcmp(input, "4"     ) == 0 || strcmp(input, "5"     ) == 0
		|| strcmp(input, "6"     ) == 0 || strcmp(input, "7"     ) == 0 || strcmp(input, "8"     ) == 0
		|| strcmp(input, "9"     ) == 0 || strcmp(input, "A"     ) == 0 || strcmp(input, "B"     ) == 0
		|| strcmp(input, "C"     ) == 0 || strcmp(input, "D"     ) == 0 || strcmp(input, "E"     ) == 0
		|| strcmp(input, "F"     ) == 0 || strcmp(input, "umL"   ) == 0 || strcmp(input, "AonB"  ) == 0 
		|| strcmp(input, "copiaA") == 0 || strcmp(input, "nAxnB" ) == 0 || strcmp(input, "AeBn"  ) == 0 
		|| strcmp(input, "nA"    ) == 0 || strcmp(input, "AenB"  ) == 0 || strcmp(input, "nAonB" ) == 0 
		|| strcmp(input, "AxB"   ) == 0 || strcmp(input, "zeroL" ) == 0 || strcmp(input, "copiaB") == 0 
		|| strcmp(input, "AeB"   ) == 0 || strcmp(input, "nB"    ) == 0 || strcmp(input, "nAeBn" ) == 0 
		|| strcmp(input, "AoB"   ) == 0 
		|| strcmp(input, "nAeB"  ) == 0 ) 
	{
		res = true;
	} else {
		printf( "\n%s\n", "[ERRO] Invalid factor!" );
	} // if
	return ( res );
} // end is_factor ( )

bool is_expression( char* input )
{
	bool res = false;
	int i = str_indexOf( input, '=' );
    if( i != -1 && is_factor(str_substring(input, 0, i-1)) && is_factor(str_substring(input, i+1, strlen(input)-2)) ) {
        res = true;
    } else {
		printf( "\n%s\n", "[ERRO] Invalid expression!" );
	} // if
	return ( res );
} // end is_expression ( )

bool is_command( char* input ) 
{
    bool res = false;
    if( input[strlen(input)-1] == ';' && str_contains(input, "=") && is_expression(input)  ) {
        res = true;
    } else {
		printf( "\n%s\n", "[ERRO] Invalid command!" );
	}// if
    return ( res );
} // end is_command ( )

#endif // __EP04_H__