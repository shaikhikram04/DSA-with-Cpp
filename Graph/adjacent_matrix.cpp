#include<iostream>
using  namespace std;

class adjacencyMatrix {
    int n;
    int **adj;
public:
    adjacencyMatrix(int n) {
        this->n = n;
        adj = new int*[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v) {
        if (u > n || v > n || u < 0 || v < 0) {
            cout << "Invalid edges!" << endl;
        }
        else {
            adj[u-1][v-1] = 1;
        }
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, maxEdges, u, v;
    cout << "Enter number of nodes : ";
    cin >> nodes;

    adjacencyMatrix am(nodes);
    maxEdges = nodes * (nodes-1);

    for (int i = 0; i < maxEdges; i++) {
        cout << "Enter edge (-1 -1 to exit) : ";
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;

        am.addEdge(u, v);
    }

    am.display();
    return 0;
}