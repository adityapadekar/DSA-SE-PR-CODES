#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class node
{
public:
    node *next;
    int data;
    int weight;
    node(int val, int wt) : next(nullptr), data(val), weight(wt) {}
};

node *addNode(node *head, int data, int weight)
{
    node *temp = new node(data, weight);
    temp->next = head;
    return temp;
}

void addEdge(node *graph[], int v, int u, int weight = 0)
{
    graph[u] = addNode(graph[u], v, weight);
    graph[v] = addNode(graph[v], u, weight);
}

void display(node *graph[], int n)
{
    cout << endl;
    for (int i{}; i < n; i++)
    {
        cout << "Vertex " << i << " -> ";
        node *temp = graph[i];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void bfs(node *graph[], int start, int v)
{

    vector<bool> visited(v, false);
    queue<int> visit;

    visit.push(start);
    visited[start] = true;
    cout << endl;
    while (!visit.empty())
    {
        int q = visit.front();
        cout << q << " ";
        visit.pop();
        node *temp = graph[q];
        while (temp)
        {
            if (!visited[temp->data])
            {
                visit.push(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }
}

void dfs(node *graph[], int start, int v)
{
    vector<bool> vis(v, false);
    stack<int> s;
    s.push(start);
    cout << endl;
    while (!s.empty())
    {
        int q = s.top();
        s.pop();
        node *temp = graph[q];
        if (vis[q] == false)
        {
            vis[q] = true;
            cout << q << " ";
        }

        while (temp)
        {
            if (!vis[temp->data])
            {
                s.push(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int v = 5;
    // vector<node *> graph(v, NULL);
    node *graph[100] = {NULL};
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 3);
    display(graph, v);
    bfs(graph, 1, v);
    dfs(graph, 1, v);
    return 0;
}
