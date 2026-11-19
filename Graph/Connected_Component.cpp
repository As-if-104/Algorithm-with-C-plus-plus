#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;                          
    vector<vector<int>> adj; 

    void DFS(int v, vector<bool> &visited)
    {
        visited[v] = true;

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                DFS(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v); 
    }

    int countComponents()
    {
        vector<bool> visited(V, false);
        int count = 0;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v])
            {
                DFS(v, visited);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    int components = g.countComponents();
    cout << "Number of connected components: " << components << endl;

    return 0;
}