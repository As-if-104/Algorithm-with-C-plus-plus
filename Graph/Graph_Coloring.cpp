#include <bits/stdc++.h>
using namespace std;

const int V = 10;

void PrintGraphColoring(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c){
    for(int i = 0; i < V; i++){
        if(graph[v][i] && color[i] == c){
            return false;
        }
    }
    return true;
}
bool graphColoringUtility(bool graph[V][V], int m, int color[], int v){
    if(v == V){
        return true;
    }

    for(int c = 1; c <= m; c++){
        if(isSafe(v, graph, color, c)){
            color[v] = c;
            if(graphColoringUtility(graph, m, color, v+1)){
                return true;
            }
            color[v] = 0; // backtracking
        }
    }
    return false;
}
bool GraphColoring(bool graph[V][V], int m){
    int color[V];
    for(int i = 0; i < V; i++){
        color[i] = 0;
    }

    if(graphColoringUtility(graph, m, color, 0) == false){
        cout << "Solution does not exist";
        return false;
    }

    PrintGraphColoring(color);
    return true;
}

void PrintGraphColoring(int color[]){
    cout << "Solution: ";
    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
}
main(){
    bool graph[V][V] = {{0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
                        {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 1, 1, 0, 0}};

    int m = 3;
    GraphColoring(graph, m);
}