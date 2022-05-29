#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{

	//Adjacency. List
	vector<vector<pair<int,int>> > l;
	int V;

public:
	Graph(int n){
		V = n;
		l.resize(n);
	}

	void addEdge(int x,int y,int w){
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int prim_mst(){
		//most important stuff
		//Init a Min Heap
		priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > Q; 

		//another array
		//visited array that denotes whether a node has been included in MST or Not
		bool * vis = new bool[V]{0};
		int ans = 0;

		//begin 
		Q.push({0,0}); // weight, node

		while(!Q.empty()){
			//pick out the edge with min weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(vis[to]){
				//discard the edge, and continue
				continue;
			}

			//otherwise take the current edge
			ans += weight;
			vis[to] = 1;

			//add the new edges in the queue
			for(auto x:l[to]){
				if(vis[x.first]==0){
					Q.push({x.second,x.first});
				}
			}
		}
		return ans;
	}

};

int main(){

	// int n,m;
	// cin>>n>>m;

	Graph g(5);
	// for(int i=0;i<m;i++){
		// int x,y,w;
		// cin>>x>>y>>w;
	g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 10);
    g.addEdge(3, 2, 6);
    g.addEdge(2, 4, 3);
	// }

	cout<<g.prim_mst()<<endl;



}
