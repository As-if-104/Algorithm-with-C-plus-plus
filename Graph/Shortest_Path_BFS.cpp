#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &graph, int S, vector<int> &par, vector<int> &dist)
{
    queue<int> q;
    dist[S] = 0;
    q.push(S);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbour : graph[node])
        {
            if (dist[neighbour] == 1e9)
            {
                par[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}

void printShortestDistance(vector<vector<int>> &graph,
                           int S, int D, int V)
{
    vector<int> par(V, -1);

    vector<int> dist(V, 1e9);

    bfs(graph, S, par, dist);

    if (dist[D] == 1e9)
    {
        cout << "Source and Destination are not connected";
        return;
    }

    vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1)
    {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V = 8, E = 10;
    int S = 2, D = 6;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);

    printShortestDistance(adj, S, D, V);
    return 0;
}