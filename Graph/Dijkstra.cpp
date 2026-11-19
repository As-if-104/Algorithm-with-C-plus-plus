#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                      
    vector<vector<pair<int, int>>> adj; 

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    vector<int> dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto x : adj[u])
            {
                int v = x.first;
                int weight = x.second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 4);

    vector<int> distances = g.dijkstra(0);

    cout << "Shortest distances from vertex 0:\n";
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "To vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}