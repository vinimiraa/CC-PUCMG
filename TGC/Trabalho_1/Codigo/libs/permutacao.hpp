#ifndef PERMUTACAO_HPP
#define PERMUTACAO_HPP

#include <iostream>
#include <vector>

using namespace std;

/**
 *  Função auxiliar para verificar se um ciclo é válido.
 *
 *  Verifica se um ciclo é válido em um grafo representado por uma matriz de adjacência.
 *
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param vertices Vetor de vértices que formam o ciclo.
 *  @param numOfvertices Número de vértices no grafo.
 *  @return true se o ciclo é válido, false caso contrário.
 */
bool isValidCycle(bool **adjMatrix, vector<int> &vertices, int numOfvertices);

/**
 * Função principal para encontrar ciclos em um grafo.
 *
 *  Encontra todos os ciclos em um grafo representado por uma matriz de adjacência.
 *
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param numOfvertices Número de vértices no grafo.
 */
void findCyclesPermutation(bool **adjMatrix, int numOfvertices);

#endif // PERMUTACAO_HPP
