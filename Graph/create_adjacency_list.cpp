#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

template <typename T>

class graph {
public: 
    unordered_map<T, list<T> > adj;

    void addEdges(T u, T v, bool direction) { 
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        adj[u].push_back(v);
        
        if (!direction)
            adj[v].push_back(u);
    }

    void printGraph() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;
    cout << "Enter the no. of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the no. of edges : ";
    cin >> m;

    graph<int> g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdges(u, v, 0);
    }

    g.printGraph();

    return 0;
}