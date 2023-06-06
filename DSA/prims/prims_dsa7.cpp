/*

You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices
with a minimum total cost. Solve the problem by suggesting appropriate data structures.

*/

#include <iostream>
using namespace std;

#define MAX 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX; v++)
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < MAX; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primMST(int graph[MAX][MAX])
{
    int parent[MAX];

    int key[MAX] = {};

    bool mstSet[MAX] = {};

    for (int i = 0; i < MAX; i++)
        key[i] = INT_MAX;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < MAX ; count++)
    {

        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < MAX; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[MAX][MAX] = {{0, 2, 0, 6, 0},
                           {2, 0, 3, 8, 5},
                           {0, 3, 0, 0, 7},
                           {6, 8, 0, 0, 9},
                           {0, 5, 7, 9, 0}};

    primMST(graph);

    return 0;
}
