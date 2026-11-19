#include<bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &stack)
    {
        visited[v] = true;

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }

        stack.push(v);
    }

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    vector<int> topologicalSort()
    {
        stack<int> stack;
        vector<bool> visited(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, stack);
            }
        }

        while (!stack.empty())
        {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }

    bool hasCycle(int v, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                if (hasCycle(neighbor, visited, recStack))
                    return true;
            }
            else if (recStack[neighbor])
                return true;
        }

        recStack[v] = false;
        return false;
    }

    bool canTopologicalSort()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (hasCycle(i, visited, recStack))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    if (!g.canTopologicalSort())
    {
        cout << "Graph contains a cycle. Topological sort is not possible." << endl;
        return 1;
    }

    vector<int> sorted = g.topologicalSort();

    cout << "Topological Sort Order: ";
    for (int vertex : sorted)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}