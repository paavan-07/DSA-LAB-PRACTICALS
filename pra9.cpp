// Practical - 9 : Develop a program to implement and demonstrate DFS and BFS graph traversal tequniques.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(0);

    cout << "\nBFS Traversal: ";
    BFS(0);

    return 0;
}