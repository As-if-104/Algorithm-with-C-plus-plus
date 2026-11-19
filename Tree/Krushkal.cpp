#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
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

    void unite(int x, int y)
    {
        int px = find(x), py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Graph
{
    int V;          
    vector<Edge> edges; 

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, int w)
    {
        edges.push_back(Edge(u, v, w));
    }

    void kruskalMST()
    {
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        vector<Edge> result; 
        int mstWeight = 0;

        cout << "Edges in Minimum Spanning Tree:\n";

        for (Edge &edge : edges)
        {
            int set1 = ds.find(edge.src);
            int set2 = ds.find(edge.dest);

            if (set1 != set2)
            {
                cout << edge.src << " -- " << edge.dest << " \tweight: " << edge.weight << endl;
                mstWeight += edge.weight;
                ds.unite(set1, set2);
                result.push_back(edge);
            }
        }

        cout << "Total MST weight: " << mstWeight << endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.kruskalMST();

    return 0;
}