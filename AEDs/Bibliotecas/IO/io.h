/**
   IO - Console input/output library.
   @author  PUC-Minas - ICEI
   @version 0.1 - 2023-1b
   
   IO - v2023-1_0.1 - __ / __ / _____
   Author: __________________________

 */
// ---------------------- lista de dependencias

#include <stdio.h>     // para entradas e saidas
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo
#include <wchar.h>     // para 16-bit characters
#include <iso646.h>    // para and, or, xor, not alternatives

// ---------------------- redefinicoes para apontamentos

#ifndef __IO_REFS__
#define __IO_REFS__

#define nullptr   NULL    // para compatibilizar com C++
#define null      NULL    // para generalizar

#define addr(p)  (&(p))   // para obter endereco
#define deref(p) (*(p))   // para obter conteudo de endereco
#define val(p)   (*(p))   // para obter conteudo apontado

#define ref       *       // para passar parametro por referencia
                          // (na assinatura)
#define var       &       // para passar parametro por referencia
                          // (na chamada)

#endif

// ---------------------- redefinicoes uteis

#ifndef _IO_H_
#define _IO_H_
                          // alternativas mais seguras, se disponiveis
#define  IO_printf        printf    // melhor: printf_s
#define  IO_scanf         scanf     // melhor: scanf_s
#define  IO_fprintf       fprintf   // melhor: fprintf_s
#define  IO_fscanf        fscanf    // melhor: fscanf_s

// ---------------------- definicoes de constantes

const   bool FALSE        = false;  // definir constante
const   bool TRUE         = true ;  // definir constante

const   char EOS          = '\0';   // definir fim de cadeia de caracteres
const   char EOL          = '\n';   // definir mudanca de linha
const   char ENDL []      = "\n";   // definir mudanca de linha

const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia
const   int  STR_SIZE     =  80 ;   // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char*   chars  ;            // definir cadeia  de caracteres
typedef int*    ints   ;            // definir arranjo de inteiros
typedef double* doubles;            // definir arranjo de reais
typedef bool*   bools  ;            // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int  IO_error   = 0;                // inicialmente sem erros
bool IO_trace   = true;             // inicialmente habilitado

// ---------------------- definicoes de funcoes e procedimentos

// ---------------------- para tratamento de erros

void IO_debugOFF ( )
{
  IO_trace = false;
} // end IO_debug_OFF ( )

void IO_debugON  ( )
{
  IO_trace = true;
} // end IO_debug_ON  ( )

void IO_debug ( bool condition, const char * const text )
{
  if ( IO_trace && condition )
  {
     IO_printf ( "\nDBG> %s\n", text );
     getchar( );
  } // end if
} // end IO_debug ( )

// ---------------------- para entradas e saidas

/**
    Metodo para limpar a saida de dados padrao.
 */
void IO_clrscr ( )
{
  if ( IO_trace )
  {
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    system ( "cls"   ); // para Windows - OBS: NAO RECOMENDADO !
#elif defined(__linux__)
    system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
#elif defined(__APPLE__) && defined(__MACH__)
    system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
#elif defined(unix) || defined(__unix__) || defined(__unix)
    system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
#else
    #error Unknown_OS
#endif
  } // end if
} // end IO_flush ( )

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush ( )
{
//  fflush ( stdin );   // para Windows - OBS: NAO RECOMENDADO !
                        // para Linux   - OBS: NAO FUNCIONA    !
    int  x = 0;         // compat�vel com o retorno de getchar()
    do { x = getchar( ); } while ( x != EOF && x != '\n' );
    clearerr ( stdin ); // reiniciar o estado de EOF
} // end IO_flush ( )

/**
    Funcao para informar a versao dessa biblioteca.
    @return versao atual
 */
chars IO_version ( )
{
    chars x = strdup ( "v.2023-1b" );
    return ( x );
} // end IO_version ( )

/**
    Metodo para identificar o programa e a autoria.
    @param text - mensagem a ser exibida
 */
void IO_id ( const char * const text )
{
    IO_printf ( "%s\n", text );
    IO_printf ( "%s\n", "Autor: ________________________" );
    IO_printf ( "\n" );          // mudar de linha
} // fim IO_id ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readint ( const char * const text )
{
    int x = 0;
    if ( IO_trace )
       IO_printf ( "%s", text   );
    IO_scanf  ( "%d", &x );
    IO_flush  ( );
    return    ( x );
} // end IO_readint ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double IO_readdouble ( const char * const text )
{
    double x = 0.0;
    if ( IO_trace )
       IO_printf ( "%s", text   );
    IO_scanf  ( "%lf", &x );
    IO_flush  ( );
    return    ( x );
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float IO_readfloat ( const char * const text )
{
    float x = 0.0;
    if ( IO_trace )
       IO_printf ( "%s", text   );
    IO_scanf  ( "%f", &x );
    IO_flush  ( );
    return    ( x );
} // end IO_readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar zero (0) para falso e
            diferente de zero para verdadeiro
 */
bool IO_readbool ( const char * const text )
{
    int x = 0;
    if ( IO_trace )
       IO_printf ( "%s", text   );
    IO_scanf  ( "%d", &x );
    IO_flush  ( );
    return    ( x!=0 );
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char IO_readchar ( const char * const text )
{
    char x = '0';
    if ( IO_trace )
       IO_printf ( "%s", text   );
    do { x = getchar( ); } while ( '\n' == x ); IO_flush  ( );
//  getchar ( );
    return ( x );
} // end IO_readchar ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
void IO_pause ( const char * const text )
{
    char x = '0';
    if ( IO_trace )
    {
       IO_printf ( "\n%s\n", text );
       do { x = getchar( ); } while ( '\n' != x );
    } // end if
} // end IO_pause ( )

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars IO_new_chars ( int size )
{
    return ( (chars) malloc ( (size+1)*sizeof(char) ) );
} // fim IO_new_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints IO_new_ints ( int size )
{
    return ( (ints) malloc ( (size)*sizeof(int) ) );
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles IO_new_doubles ( int size )
{
    return ( (doubles) malloc ( (size)*sizeof(double) ) );
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bools IO_new_bools ( int size )
{
    return ( (bools) malloc ( (size)*sizeof(bool) ) );
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
chars IO_concat ( const char * const text1, const char * const text2 )
{                               // reservar area
    chars buffer = IO_new_chars ( strlen(text1)+strlen(text2)+1 );
    strcpy ( buffer, text1 );
    strcat ( buffer, text2 );
    return ( buffer );
} // fim IO_concat ( )

/**
    Funcao para converter valor logico para caracteres.
    @return cadeia com o resultado
    @param x     - valor logico
 */
chars IO_toString_b ( bool x )
{                               // reservar area
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%d", x );// variante do printf( )
    return  ( buffer );
} // fim IO_toString_b ( )

/**
    Funcao para converter caractere para caracteres.
    @return cadeia com o resultado
    @param x     - caractere
 */
chars IO_toString_c ( char x )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%c", x );// variante do printf( )
    return  ( buffer );
} // fim IO_toString_c ( )

/**
    Funcao para converter inteiro para caracteres.
    @return cadeia com o resultado
    @param x     - valor inteiro
 */
chars IO_toString_d ( int x )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%d", x );// variante do printf( )
    return  ( buffer );
} // fim IO_toString_d ( )

/**
    Funcaoo para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
chars IO_toString_f ( double x )
{                               // variante do printf( )
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    sprintf ( buffer, "%lf", x );
    return  ( buffer );
} // fim IO_toString_f ( )

/**
    Metodo para mostrar uma linha com certo texto.
    @param text - texto a ser exibido
 */
void IO_print ( const char * const text )
{
    IO_printf ( "%s", text );
//      puts ( text );
} // fim IO_print ( )

/**
    Metodo para mostrar uma linha com certo texto
    e mudar de linha.
    @param text - texto a ser exibido
 */
void IO_println ( const char * const text )
{
    IO_printf ( "%s\n", text );
//  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )

/**
    Metodo para gravar uma linha em arquivo texto.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void IO_fprint ( FILE* filePtr, const char * const text )
{
    IO_fprintf ( filePtr, "%s", text );
} // fim IO_fprint ( )

/**
    Metodo para gravar uma linha em arquivo texto
    e mudar de linha.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void IO_fprintln ( FILE* filePtr, const char * const text )
{
    IO_fprintf ( filePtr, "%s\n", text );
} // fim IO_fprintln ( )

/**
    Funcao para ler uma cadeia de caracteres de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
chars IO_fread ( FILE* filePtr )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );

    IO_fscanf ( filePtr, "%s", buffer ); // ler uma cadeia
    return ( buffer );
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
chars IO_freadln ( FILE* filePtr )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );

    fgets  ( buffer, STR_SIZE, filePtr ); // ler uma linha
    buffer [ strlen (buffer)-1 ] = EOS;   // reposicionar o fim de linha
    return ( buffer );
} // fim IO_freadln ( )

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text - mensagem a ser exibida antes da leitura
 */
chars IO_readstring ( const char * const text )
{
    chars buffer = IO_new_chars ( STR_SIZE+1 );
    if ( IO_trace )
       IO_printf ( "%s", text   );
    IO_scanf  ( "%80s", buffer );  // ler cadeia de caracteres
                                   // com limitacao de 80 posicoes
    IO_flush  ( );
    return ( buffer );
} // fim IO_readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text - mensagem a ser exibida antes da leitura
 */
chars IO_readln ( const char * const text )
{
    if ( IO_trace )
       IO_printf ( "%s", text   );
    return ( IO_freadln ( stdin ) );
} // fim IO_readln ( )

/**
    Funcao para converter valor logico para cadeia de caracteres.
    @return "true", se verdadeiro; "false", caso contrario
    @param  value - valor a ser convertido
 */
chars IO_boolalpha ( bool value )
{
    if ( value )
       return ( strdup ("true"  ) );
    else
       return ( strdup ("false" ) );
} // fim IO_boolalpha ( )

/**
    Funcao para comparar conteudos em memoria.
    @return true, se iguais; false, caso contrario
    @param  p1   - endereco do primeiro valor
    @param  p2   - endereco do segundo  valor
    @param  size - tamanho em bytes a ser comparado
 */
bool IO_check ( void *p1, void *p2, unsigned int size )
{
    return ( p1 && p2 && (0==memcmp( p1, p2, size )) );
} // fim IO_check ( )

/**
    Funcao para retornar o tamanho de cadeia de caracteres.
    @return tamanho, se existir; 0, caso contrario
    @param  text  - cadeia de caracteres
 */
int IO_length ( char* text )
{
    int x = 0;
    if ( text )
    { x = strlen(text); }
    return ( x );
} // fim IO_length ( )

/**
    Funcao para obter simbolo de certa posicao 
    em cadeia de caracteres.
    @return simbolo, se existir; '\0', caso contrario
    @param  text  - cadeia de caracteres
    @param  index - posicao desejada
 */
char IO_charAt ( char* text, unsigned int index )
{
    char x = '\0';
    if ( text && index < strlen(text) )
    {  x = text [ index ]; }
    return ( x );
} // fim IO_charAt ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text  - cadeia de caracteres
    @param  start - onde comecar
    @param  size  - quantos caracteres copiar
 */
char* IO_substring ( char *text, int start, unsigned int size )
{
    chars buffer = NULL;
    if ( start >= 0 && (start+size) < (int) strlen(text) )
    {
       buffer = IO_new_chars ( size+1 );
       memcpy ( buffer, text+start, size );
       buffer [size] = '\0';
    }
    return ( buffer );
} // fim IO_substring ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text   - cadeia de caracteres
    @param  symbol - caractere a ser acrescentado
 */
char* IO_strapp ( char *text, char symbol )
{
    chars buffer = NULL;
    int size     = 0   ;
    if ( text )
    {
       size   = strlen ( text );
       buffer = IO_new_chars ( size+1 );
       memcpy ( buffer, text, size );
       buffer [size  ] = symbol;
       buffer [size+1] = '\0'  ;
    }
    return ( buffer );
} // fim IO_strapp ( )

#endif
