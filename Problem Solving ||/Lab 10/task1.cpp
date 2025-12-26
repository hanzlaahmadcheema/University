#include <iostream>
using namespace std;

int main() {

    const int V = 5;
    int adj[V][V] = {0};

    int edges[4][2] = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3}
    };

    for (int i = 0; i < 4; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "Adjacency Matrix created for 5 vertices and 4 edges:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
