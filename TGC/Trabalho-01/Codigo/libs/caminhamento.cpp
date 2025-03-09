#include <iostream>
#include <sstream>
#include "caminhamento.hpp"

using namespace std;

void DFSUtil(bool **adjMatrix, int numOfvertices, int vertex, bool *visited, int *path, int pathIndex, int startVertex, string *foundCycles, int &cycleCount)
{
    visited[vertex] = true;
    path[pathIndex] = vertex;
    pathIndex++;

    // Explora todos os vizinhos do vértice atual
    for (int i = 0; i < numOfvertices; i++)
    {
        if (adjMatrix[vertex][i])
        { // Se há uma aresta entre vertex -> i
            if (!visited[i])
            {
                DFSUtil(adjMatrix, numOfvertices, i, visited, path, pathIndex, startVertex, foundCycles, cycleCount);
            }
            else if (i == startVertex && pathIndex > 2)
            {
                // Encontramos um ciclo válido (volta ao início e tem pelo menos 3 vértices)

                // Usando stringstream para formatar corretamente o ciclo
                stringstream cycle;
                for (int j = 0; j < pathIndex; j++)
                {
                    cycle << char('A' + path[j]) << " "; // Concatena o vértice atual no ciclo
                }
                cycle << char('A' + startVertex); // Fecha o ciclo, incluindo o vértice de início

                string cycleString = cycle.str(); // Converte para string

                // Verifica se o ciclo já foi encontrado
                bool cycleFound = false;
                for (int k = 0; k < cycleCount; k++)
                {
                    if (foundCycles[k] == cycleString)
                    {
                        cycleFound = true;
                        break;
                    }
                }

                if (!cycleFound)
                {
                    // Se o ciclo não foi encontrado antes, imprime e armazena
                    cout << "Cycle found: " << cycleString << endl;
                    foundCycles[cycleCount] = cycleString; // Armazena o ciclo
                    cycleCount++;                          // Incrementa o contador de ciclos encontrados
                }
            }
        }
    }

    // Retrocede para explorar outros caminhos
    visited[vertex] = false;
}

void findCyclesDFS(bool **adjMatrix, int numOfvertices)
{
    bool *visited = new bool[numOfvertices]();                       // Array de vértices visitados
    int *path = new int[numOfvertices];                              // Array para armazenar o caminho atual
    string *foundCycles = new string[numOfvertices * numOfvertices]; // Array para armazenar ciclos encontrados
    int cycleCount = 0;                                              // Contador de ciclos encontrados

    // Chama DFS para cada vértice
    for (int i = 0; i < numOfvertices; i++)
    {
        DFSUtil(adjMatrix, numOfvertices, i, visited, path, 0, i, foundCycles, cycleCount);
    }

    // Libera a memória alocada
    delete[] visited;
    delete[] path;
    delete[] foundCycles;
}