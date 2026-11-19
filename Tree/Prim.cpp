#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                            
    vector<vector<pair<int, int>>> adj; 

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void primMST()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0;

        vector<int> key(V, INT_MAX);

        vector<int> parent(V, -1);

        vector<bool> inMST(V, false);

        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;

            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        int mstWeight = 0;
        cout << "Edges in Minimum Spanning Tree:\n";
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " -- " << i << " \tweight: " << key[i] << endl;
            mstWeight += key[i];
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

    g.primMST();

    return 0;
}