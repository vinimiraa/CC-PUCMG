#ifndef CAMINHAMENTO_HPP
#define CAMINHAMENTO_HPP

#include <iostream>
#include <sstream>

using namespace std;

/**
 *  Função auxiliar DFS para detectar ciclos.
 *  
 *  Realiza uma busca em profundidade (DFS) a partir de um vértice no grafo e 
 *  identifica ciclos que retornam ao vértice de início.
 *  
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param numOfvertices Número de vértices no grafo.
 *  @param vertex Vértice atual na busca em profundidade.
 *  @param visited Array de vértices visitados.
 *  @param path Array que armazena o caminho atual da DFS.
 *  @param pathIndex Índice atual no caminho da DFS.
 *  @param startVertex Vértice de início do ciclo.
 *  @param foundCycles Array para armazenar ciclos encontrados.
 *  @param cycleCount Contador de ciclos encontrados.
 */
void DFSUtil(bool **adjMatrix, int numOfvertices, int vertex, bool *visited, int *path, int pathIndex, int startVertex, string *foundCycles, int &cycleCount);

/**
 *  Função principal para encontrar ciclos no grafo.
 *  
 *  Chama a função auxiliar DFS para detectar ciclos a partir de cada vértice do grafo.
 *  
 *  @param adjMatrix Matriz de adjacência do grafo.
 *  @param numOfvertices Número de vértices no grafo.
 */
void findCyclesDFS(bool **adjMatrix, int numOfvertices);

#endif // CAMINHAMENTO_HPP