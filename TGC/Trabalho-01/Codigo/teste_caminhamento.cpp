// $ g++ -o teste_caminhamento teste_caminhamento.cpp libs/grafo.cpp libs/caminhamento.cpp
// $ ./teste_caminhamento

#include <iostream>
#include "libs/grafo.hpp"
#include "libs/caminhamento.hpp"

using namespace std;

int main()
{
    int numOfvertices;

    cout << "Enter the number of vertices: ";
    cin >> numOfvertices;

    while (numOfvertices <= 0)
    {
        cout << "Invalid number of vertices! Please enter a positive number: ";
        cin >> numOfvertices;
    }

    bool **adjMatrix = new bool *[numOfvertices];

    initAdjMatrix(adjMatrix, numOfvertices);

    printAdjMatrix(adjMatrix, numOfvertices);

    cout << endl
         << "Enumerating all cycles of the graph..." << endl;
    findCyclesDFS(adjMatrix, numOfvertices);

    for (int i = 0; i < numOfvertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}