#include <iostream>
#include "grafo.hpp"

using namespace std;

void initAdjMatrix(bool **adjMatrix, int numOfvertices)
{
    for (int i = 0; i < numOfvertices; i++)
    {
        adjMatrix[i] = new bool[numOfvertices]();
    }

    cout << endl
         << "Enter the adjacency matrix: (v1 v2) (0 0 to stop)" << endl;

    char v1, v2;
    while (true)
    {
        cin >> v1 >> v2;

        if (v1 == '0' && v2 == '0')
        {
            break;
        }

        if (v1 == v2)
        {
            cout << "Loops are not allowed in simple graphs! Please enter a valid edge." << endl;
            continue;
        }

        if (v1 < 'A' || v1 >= 'A' + numOfvertices || v2 < 'A' || v2 >= 'A' + numOfvertices)
        {
            cout << "Invalid vertices! Please enter vertices between A and " << char('A' + numOfvertices - 1) << endl;
            continue;
        }

        int i = v1 - 'A';
        int j = v2 - 'A';

        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true; // Undirected graph
    }
}

void printAdjMatrix(bool **adjMatrix, int numOfvertices)
{
    cout << endl
         << "The adjacency matrix is: " << endl;

    for (int i = 0; i < numOfvertices; i++)
    {
        for (int j = 0; j < numOfvertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}