#include<bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph
{
private:
    int V, E;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back(Edge(src, dest, weight));
        E = edges.size();
    }

    vector<int> bellmanFord(int source)
    {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (const Edge &edge : edges)
            {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;

                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (const Edge &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                cout << "Negative cycle detected!" << endl;
                return vector<int>();
            }
        }

        return dist;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    vector<int> dist = g.bellmanFord(0);

    if (!dist.empty())
    {
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }

    return 0;
}