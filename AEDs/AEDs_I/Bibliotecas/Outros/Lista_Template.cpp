/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados I
 *  
 *  Exercicios0X - v0.0. - __ / __ / ____
 *  Author: Vinicius Miranda de Araujo
 *  
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o Exercicios0X Exercicios0X.cpp
 *       Windows: gcc -o Exercicios0X Exercicios0X.cpp
 *  
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./Exercicios0X
 *       Windows: Exercicios0X
 *  
 */

// -------------------------- lista de dependencias

#include "libshow.hpp"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 *  Metodo01.
 */
void exercicio0X11( void )
{
    // identificacao
    id( "Exercicio 0X11:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X11 (  )

/**
 *  Metodo02.
 */
void exercicio0X12( void )
{
    // identificacao
    id( "Exercicio 0X12:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X12 (  )

/**
 *  Metodo03.
 */
void exercicio0X13( void )
{
    // identificacao
    id( "Exercicio 0X13:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X13 (  )

/**
 *  Metodo04.
 */
void exercicio0X14( void )
{
    // identificacao
    id( "Exercicio 0X14:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X14 (  )

/**
 *  Metodo05.
 */
void exercicio0X15( void )
{
    // identificacao
    id( "Exercicio 0X15:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X15 (  )

/**
 *  Metodo06.
 */
void exercicio0X16( void )
{
    // identificacao
    id( "Exercicio 0X16:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X16 (  )

/**
 *  Metodo07.
 */
void exercicio0X17( void )
{
    // identificacao
    id( "Exercicio 0X17:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X17 (  )

/**
 *  Metodo08.
 */
void exercicio0X18( void )
{
    // identificacao
    id( "Exercicio 0X18:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X18 (  )

/**
 *  Metodo0X.
 */
void exercicio0X19( void )
{
    // identificacao
    id( "Exercicio 0X19:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X19 (  )

/**
 *  Metodo10.
 */
void exercicio0X20( void )
{
    // identificacao
    id( "Exercicio 0X20:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0X20 (  )

/**
 *  Metodo11.
 */
void exercicio0XE1( void )
{
    // identificacao
    id( "Exercicio 0XE1:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0XE1 (  )

/**
 *  Metodo12.
 */
void exercicio0XE2( void )
{
    // identificacao
    id( "Exercicio 0XE2:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio0XE2 (  )

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 0X11    " << std::endl;
    std::cout << "  2 - Exercicio 0X12    " << std::endl;
    std::cout << "  3 - Exercicio 0X13    " << std::endl;
    std::cout << "  4 - Exercicio 0X14    " << std::endl;
    std::cout << "  5 - Exercicio 0X15    " << std::endl;
    std::cout << "  6 - Exercicio 0X16    " << std::endl;
    std::cout << "  7 - Exercicio 0X17    " << std::endl;
    std::cout << "  8 - Exercicio 0X18    " << std::endl;
    std::cout << "  9 - Exercicio 0X19    " << std::endl;
    std::cout << " 10 - Exercicio 0X20    " << std::endl;
    std::cout << " 11 - Exercicio 0XE1    " << std::endl;
    std::cout << " 12 - Exercicio 0XE2    " << std::endl;
    std::cout << std::endl;
} // fim menuOpcoes()

// -------------------------- definicao do metodo principal

int main( void )
{
    int opcao = 0;

    do
    {
        // limpar a saida de dados
        clearscreen(  );

        // mostrar identificacao do autor e programa
        id( "Programa: Exercicios0X - v0.0" );

        // mostrar menu de opcoes
        menuOpcoes(  );

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch ( opcao )
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            exercicio0X11(  );
            break;
        case 2:
            exercicio0X12(  );
            break;
        case 3:
            exercicio0X13(  );
            break;
        case 4:
            exercicio0X14(  );
            break;
        case 5:
            exercicio0X15(  );
            break;
        case 6:
            exercicio0X16(  );
            break;
        case 7:
            exercicio0X17(  );
            break;
        case 8:
            exercicio0X18(  );
            break;
        case 9:
            exercicio0X19(  );
            break;
        case 10:
            exercicio0X20(  );
            break;
        case 11:
            exercicio0XE1(  );
            break;
        case 12:
            exercicio0XE2(  );
            break;
        default:
            pause( "ERRO: opcao invalida" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}
