#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>

using namespace std;

/**
 *  Inicializa a matriz de adjacência com as arestas fornecidas.
 *  
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param numOfvertices Número de vértices no grafo.
 */
void initAdjMatrix(bool **adjMatrix, int numOfvertices);

/**
 *  Imprime a matriz de adjacência do grafo.
 *  
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param numOfvertices Número de vértices no grafo.
 */
void printAdjMatrix(bool **adjMatrix, int numOfvertices);

#endif // GRAFO_HPP