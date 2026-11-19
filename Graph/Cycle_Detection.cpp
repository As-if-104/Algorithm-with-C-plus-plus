#include <bits/stdc++.h>
using namespace std;

class DirectedGraph
{
    int V;
    vector<list<int>> adj;

    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }

        recStack[v] = false;
        return false;
    }

public:
    DirectedGraph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool hasCycle()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};

class UnionFind
{
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);

        if (px == py)
            return false;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

class UndirectedGraph
{
    int V;
    vector<pair<int, int>> edges;

public:
    UndirectedGraph(int vertices) : V(vertices) {}

    void addEdge(int v, int w)
    {
        edges.push_back({v, w});
    }

    bool hasCycle()
    {
        UnionFind uf(V);

        for (auto &edge : edges)
        {
            if (!uf.unite(edge.first, edge.second))
                return true; 
        }
        return false;
    }
};

int main()
{
    DirectedGraph dg(4);
    dg.addEdge(0, 1);
    dg.addEdge(1, 2);
    dg.addEdge(2, 3);
    dg.addEdge(3, 1);

    cout << "Directed graph has cycle: " << (dg.hasCycle() ? "Yes" : "No") << endl;

    UndirectedGraph ug(4);
    ug.addEdge(0, 1);
    ug.addEdge(1, 2);
    ug.addEdge(2, 3);
    ug.addEdge(3, 0);

    cout << "Undirected graph has cycle: " << (ug.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}