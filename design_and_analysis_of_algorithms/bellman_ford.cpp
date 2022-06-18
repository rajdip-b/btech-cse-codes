#include <iostream>
#include <vector>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int>> edgeList) {
    // Initialize distance array
    vector<int> distances(V, INT16_MAX);
    
    // Set source node at zero distance from itself
    distances[src] = 0;

    // Relax the edgelist for V-1 times
    for (int x = 0; x < V - 1; x++) {
        for (auto edge: edgeList) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (distances[u] != INT16_MAX && distances[u] + wt < distances[v])
                distances[v] = distances[u] + wt;
        }
    }

    // Check for negetive edges
    for (auto edge: edgeList) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (distances[u] != INT16_MAX && distances[u] + wt < distances[v]){
            cout << "Negetive edge found. Exiting...";
            exit(1);
        }
    }

    // Return distances if everything goes right
    return distances;
}

int main() {
    int edges, vertices;
    cin >> edges >> vertices;

    vector<vector<int>> edgeList; // <u, v, weight>
    for (int x = 0; x < edges; x++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edgeList.push_back({u, v, wt});
    }

    vector<int> distances = bellman_ford(vertices, 0, edgeList);

    for (int x = 0; x < vertices; x++)
        cout << "Node " << x << " is at distance " << distances[x] << endl;

    return 0;
}