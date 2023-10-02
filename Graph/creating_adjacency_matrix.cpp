

// T.C -> O(m)
// S.C -> O(n*n)


#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> & edges) {
    vector<vector<int>> adjacencyMatrix(n, vector<int> (n, 0));

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyMatrix[u][v] = 1;
    }

    return adjacencyMatrix;
}

int main() {

    int n = 4;
    vector<vector<int>> edges = {{1,2}, {0,3}, {2,3}};

    vector<vector<int>> adjacencyMatrix = printAdjacency(n, 3, edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}