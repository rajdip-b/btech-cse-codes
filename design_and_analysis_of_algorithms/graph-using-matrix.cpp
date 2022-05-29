#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<int>> adj;

void addEdge (int x, int y) {
    // undirected graph
    adj[x][y] = 1;
    adj[y][x] = 1;
}   

void bfs(int vertex) {
    vector<bool> visited (adj.size(), false);
    queue<int> vertices;

    vertices.push(vertex);
    visited[vertex] = true;

    while (!vertices.empty()) {
        int current = vertices.front();
        vertices.pop();

        cout<<current<<" ";

        for (int i=0;i<adj[current].size();i++){
            if (adj[current][i] == 1 && !visited[i]) {
                vertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void dfs (int vertex, vector<bool>& visited) {
    cout<<vertex<<" ";
    visited[vertex] = true;
    for (int x=0;x<adj[vertex].size();x++) {
        if (adj[vertex][x] == 1 && ! visited[x]){
            dfs(x, visited);
        }
    }
}

int main() {
    int V = 10;
    adj = vector<vector<int>>(V, vector<int>(V, 0));
    addEdge(1,2);
    addEdge(2,5);
    addEdge(5,4);
    addEdge(4,2);
    addEdge(4,3);
    addEdge(3,1);
    vector<bool> visited(V, false); 
    dfs(2, visited);
    cout<<endl;
    bfs(2);
    cout<<endl;
}