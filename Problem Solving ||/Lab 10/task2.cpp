#include <iostream>
using namespace std;

const int V = 5;

bool checkEdge(int adj[V][V], int u, int v) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
        return adj[u][v] == 1;
    }
    return false;
}

int main() {
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

    int u = 1, v = 2;
    cout << "Checking edge between " << u << " and " << v << ": ";
    if (checkEdge(adj, u, v)) {
        cout << "Edge exists." << endl;
    } else {
        cout << "Edge does not exist." << endl;
    }

    u = 3; v = 4;
    cout << "Checking edge between " << u << " and " << v << ": ";
    if (checkEdge(adj, u, v)) {
        cout << "Edge exists." << endl;
    } else {
        cout << "Edge does not exist." << endl;
    }

    return 0;
}
