#include <iostream>
#include <algorithm>
#include <vector>
#include "permutacao.hpp"

using namespace std;

bool isValidCycle(bool **adjMatrix, vector<int> &vertices, int numOfvertices)
{
    for (int i = 0; i < numOfvertices; ++i)
    {
        int u = vertices[i];
        int v = vertices[(i + 1) % numOfvertices];
        if (!adjMatrix[u][v])
            return false;
    }
    return true;
}

void findCyclesPermutation(bool **adjMatrix, int numOfvertices)
{
    vector<int> vertices(numOfvertices);
    int count = 0;

    // Initialize the vertices
    for (int i = 0; i < numOfvertices; ++i)
    {
        vertices[i] = i;
    }

    // r = number of vertices in the cycle
    // (a cycle must have at least 3 vertices)
    for (int r = 3; r <= numOfvertices; r++)
    {
        int tmp = count;
        cout << endl
             << "Cycles with " << r << " vertices: " << endl;

        vector<bool> select(numOfvertices);
        fill(select.end() - r, select.end(), true);
        do
        {
            vector<int> combination;
            for (int i = 0; i < numOfvertices; i++)
            {
                if (select[i])
                {
                    combination.push_back(vertices[i]);
                }
            }

            do
            {
                if (isValidCycle(adjMatrix, combination, r))
                {
                    count++;
                    for (int v : combination)
                    {
                        cout << char('A' + v) << " ";
                    }

                    cout << char('A' + combination[0]) << endl;
                }
            } while (next_permutation(combination.begin(), combination.end()));
        } while (next_permutation(select.begin(), select.end()));

        cout << "Total number of cycles with " << r << " vertices: " << count - tmp << endl
             << endl;
    }

    cout << "-- Total number of cycles: " << count << " --" << endl;
}