#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  Funcao que encontra o maior palindromo nao consecutivo em uma string.
 *  O algoritmo utiliza uma abordagem de programacao dinamica para construir uma tabela
 *  que armazena o tamanho do maior palindromo encontrado em cada ponto da comparacao entre 
 *  a string original e sua versao reversa.
 *  
 *  Complexidade:
 *  - Construcao da string reversa: O(n)
 *  - Construcao da tabela de programacao dinamica: O(n^2)
 *  
 *  @param string A string de entrada na qual se deseja encontrar o maior palindromo nao consecutivo.
 *  @return Retorna o maior palindromo nao consecutivo encontrado.
 */
char* longestPalindrome(char* string) 
{
    int n = strlen(string); // Tamanho da string original

    // --------- Criacao da string reversa
    // A string reversa sera usada para comparar com a string original e encontrar as correspondências
    char* reversed = (char*)malloc((n+1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        reversed[i] = string[n - 1 - i];
    }
    reversed[n] = '\0';
    
    // --------- Alocacao de memoria para as matrizes de programacao dinamica
    // A matriz L armazenara o tamanho do maior palindromo encontrado até cada posicao
    int** L = (int**) malloc((n+1) * sizeof(int*));

    // A matriz directions armazenara as direcoes usadas para reconstruir o palindromo
    // 0 = nenhum movimento, 1 = diagonal (match), 2 = cima, 3 = esquerda
    int** directions = (int**) malloc((n+1) * sizeof(int*));
    
    // Inicializando as matrizes com 0
    for(int i = 0; i <= n; i++)
    {
        L[i] = (int*) calloc((n+1), sizeof(int));
        directions[i] = (int*) calloc((n+1), sizeof(int));
    }
    
    // --------- Preenchendo as matrizes L e directions
    // Relacao de Recorrencia 
    // L(i,j) = {
    //      0                         , se i = 0 ou j = 0
    //      L(i-1, j-1) + 1           , se string[i] == reversa[j]
    //      max(L(i, j-1), L(i-1, j)) , se string[i] != reversa[j]
    // }
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            // Se os caracteres da string original e reversa forem iguais
            if(string[i - 1] == reversed[j - 1]) 
            {
                L[i][j] = L[i-1][j-1] + 1; // Aumenta o tamanho do palindromo
                directions[i][j] = 1;      // Direcao diagonal (match)
            }
            // Se os caracteres sao diferentes, escolhemos o valor maximo entre cima ou esquerda
            else if (L[i - 1][j] >= L[i][j - 1]) 
            {
                L[i][j] = L[i - 1][j]; // Mantém o maior valor vindo de cima
                directions[i][j] = 2;  // Direcao de cima
            } else 
            {
                L[i][j] = L[i][j - 1]; // Mantém o maior valor vindo da esquerda
                directions[i][j] = 3;  // Direcao da esquerda
            }
        }
    }
    
    // O tamanho do maior palindromo nao consecutivo encontrado sera o valor na ultima celula da matriz L
    int len = L[n][n];

    // ---------- Construcao do palindromo
    // Usamos a tabela de direcoes para reconstruir o palindromo, comecando da ultima celula e indo para tras
    char* palindrome = (char*) calloc((len+1), sizeof(char));
    palindrome[len] = '\0';

    int i = n, j = n;
    int pos = len - 1;
    while (i > 0 && j > 0) 
    {
        if (directions[i][j] == 1)  // Direção diagonal (match)
        {
            palindrome[pos--] = string[i - 1]; // Adiciona o caractere correspondente ao palíndromo
            i--;
            j--;
        } else if (directions[i][j] == 2) { // Direção de cima
            i--;
        } else { // Direção da esquerda
            j--;
        }
    }

    // Retorna o maior palíndromo não consecutivo
    return palindrome;
}

// gcc maiorPalindromoNaoConsecutivo.c
int main(int argc, char* argv[])
{
    printf("%s\n", longestPalindrome("aacabdkacaa"));
    return 0;
}
