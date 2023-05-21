/*

Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS.
Use the map of the area around the college as the graph.
Identify the prominent land marks as nodes and perform DFS and BFS on that.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 5

using namespace std;

void addEdge(int adjMat[][MAX], int v, int u)
{
    adjMat[v][u] = 1;
    adjMat[u][v] = 1;
}

void display(int adjMat[][MAX], int v)
{
    if (!v)
    {
        cout << "The graph is Empty" << endl;
        return;
    }
    cout << endl;
    for (int i{}; i < v; i++)
    {

        cout << "Vertex " << i << " -> ";
        for (int j{}; j < v; j++)
        {
            if (adjMat[i][j])
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void dfs(int adjMat[][MAX], int v, int start)
{
    int visited[v] = {0};
    stack<int> s;
    s.push(start);
    cout << endl;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        if (!visited[temp])
        {
            visited[temp] = 1;
            cout << temp << " ";
        }
        for (int i{}; i < v; i++)
        {
            if (adjMat[temp][i] != 0 && visited[i] == 0)
            {
                s.push(i);
            }
        }
    }
}

void bfs(int adjMat[][MAX], int v, int start)
{

    bool visited[v] = {0};
    queue<int> visit;
    visit.push(start);
    visited[start] = 1;
    cout << endl;
    while (!visit.empty())
    {
        int temp = visit.front();
        visit.pop();
        cout << temp << " ";

        for (int i{}; i < v; i++)
        {
            if (adjMat[temp][i] && !visited[i])
            {
                visit.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int v, e;
    // cout << "Enter the number if Vertices present in the graph : ";
    // cin >> v;
    v = 5;
    int adjMat[MAX][MAX] = {0};
    addEdge(adjMat, 1, 2);
    addEdge(adjMat, 1, 3);
    addEdge(adjMat, 1, 4);
    addEdge(adjMat, 2, 4);
    addEdge(adjMat, 2, 3);
    display(adjMat, v);
    dfs(adjMat, v, 1);
    bfs(adjMat, v, 1);

    return 0;
}
