// $ g++ -o teste_permutacao teste_permutacao.cpp libs/grafo.cpp libs/permutacao.cpp
// $ ./teste_permutacao

#include <iostream>
#include "libs/grafo.hpp"
#include "libs/permutacao.hpp"

int main()
{
    int numOfvertices;
    cout << "Enter the number of vertices: ";
    cin >> numOfvertices;

    bool **adjMatrix = new bool *[numOfvertices];
    initAdjMatrix(adjMatrix, numOfvertices);
    printAdjMatrix(adjMatrix, numOfvertices);

    findCyclesPermutation(adjMatrix, numOfvertices);

    // Free the memory
    for (int i = 0; i < numOfvertices; ++i)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}