#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Graph {
    int V;
    // Stores edges in sorted order
    set<pair<int, int>> distanceQueue; // <weight, node>
    // Stores minimum distance from src to dest
    vector<int> *minDistances;
    vector<vector<pair<int, int>>> edgeList; //x { [ y1, w1 ], [y2, w2] }

public:
    Graph(int V) {
        this->V = V;
        edgeList.resize(V);
        minDistances = new vector<int>(V, INT32_MAX);
    }

    void addEdge(int x, int y, int w) {
        edgeList[x].push_back({y, w});
    }

    void dijkstras(int src, int dest) {
        // Insert the src element into the set
        (*minDistances)[src] = 0;
        distanceQueue.insert({0, src});

        while (!distanceQueue.empty()) {
            // Pop out the first element
            auto it = distanceQueue.begin();
            int node = it->second;
            int weightTillNow = it->first;
            distanceQueue.erase(it);

            // Loop through all the neighbours of 'node'
            for (auto edge: edgeList[node]) {
                int currentNode = edge.first;
                int currentWeight = edge.second;

                if (currentWeight + weightTillNow < (*minDistances)[currentNode]) {

                    // Remove any existing entry of the node, weight pair
                    auto i = distanceQueue.find({(*minDistances)[currentNode], currentNode});
                    if (i != distanceQueue.end()) {
                        distanceQueue.erase(i);
                    }

                    // Insert the edges from the current node
                    (*minDistances)[currentNode] = currentWeight + weightTillNow;
                    distanceQueue.insert({(*minDistances)[currentNode], currentNode});
                }
            }
        }
        for (int i = 0; i < V; i++) {
            cout<<src<<" to "<<i<<": "<<(*minDistances)[i]<<endl;
        }
        cout<<"Minimum distance from 0 to 3 is: "<<(*minDistances)[dest]<<endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);
    g.dijkstras(0, 3);
    return 0;
}