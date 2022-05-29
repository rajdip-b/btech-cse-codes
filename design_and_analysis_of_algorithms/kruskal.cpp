#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class DSU {
    int *rank;
    int *parent;

public:
    DSU(int v) {
        rank = new int[v];
        parent = new int[v];

        for (int x=0;x<v;x++) {
            rank[x] = 1;
            parent[x] = -1;
        }
    }

    int find_set(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find_set(parent[i]);
    }

    void union_set(int x, int y) {
        int s1 = find_set(x);
        int s2 = find_set(y);

        if (s1 != s2) {
            if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += s2;
            }else{
                parent[s1] = s2;
                rank[s2] += s1;
            }
        }
    }
};

class Graph {
    int v;
    vector<vector<int>> edgeList;

public:
    Graph(int v) {
        this->v = v;
    }

    void addEdge(int x, int y, int w) {
        edgeList.push_back({w,x,y});
    }

    void kruskal_mst() {
        // Sort the edges in ascending order based on path weight
        sort(edgeList.begin(), edgeList.end());

        // Stores the minimum path
        int ans = 0;

        // DSU for loop detection
        DSU s(v);

        // For each edge in sorted order, check if connecting them forms a cycle or not.
        // If no, add the weight to the ans
        for (auto edge: edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find_set(x) != s.find_set(y)) {
                s.union_set(x, y);
                ans += w;
            }
        }

        cout<<ans<<endl;
    }
};

int main(){
    Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);

    g.kruskal_mst();

    return 0;
}