#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

vector<list<int>> adj;

void addEdge(int x, int y) {
    // undirected graph
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void bfs (int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> vertices;

    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty()) {
        int current = vertices.front();
        vertices.pop();

        cout<<current<<" ";

        for (auto& v : adj[current]){
            if (!visited[v]){
                vertices.push(v);
                visited[v] = true;
            }
        }
    }
}

void dfs (int vertex, vector<bool>& visited) {
    cout<<vertex<<" ";
    visited[vertex] = true;
    for (auto &v : adj[vertex]) {
        if (!visited[v]){
            dfs(x, visited);
        }
    }
}

int main(){
    int V = 10;
    adj.resize(V);
    addEdge(1,2);
    addEdge(2,5);
    addEdge(5,4);
    addEdge(4,2);
    addEdge(4,3);
    addEdge(3,1);
    bfs(2);
    cout<<endl;
    vector<bool> visited (V, false);
    dfs(2, visited);
    cout<<endl;
    return 0;
}