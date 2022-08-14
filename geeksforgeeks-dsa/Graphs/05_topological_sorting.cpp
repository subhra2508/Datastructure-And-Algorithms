// topological sort is only possible if the graph is directed acyclic graph,
//directed acyclic mean : graph is directed and there is no cycle present ok 😃


// we can implement it simply using : DFS + Stack

// The Applications of Topological Sort are: 
// Finding cycle in a graph. 
// Operating System deadlock detection.
//  Dependency resolution.



#include<bits/stdc++.h>
using namespace std;
 
class Graph {
	int V;
	list<int>*adj
	void topologicalSortUtil(int v,vector<bool>visited,stack<int> &stk);
public:
	Graph(int V);
	void addEdge(int v,int w);
	void topologicalSort();
};


Graph::Graph(int V){
	this->V = V;
	adj = new List<int>[V];
}


void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}

//recursion function used by topological sort
void Graph::topologicalSortUtil(int v,vector<bool>visited,stack<int>&stk){
	visited[v]=true;

	//recur for all the vertices adjacent to this vertice
	for(auto i=adj[v].begin();i!=adj[v].end();i++){
		if(!visited[*i]){
			topologicalSortUtil(*i,visited,stk);
		}
	}

	//push current vertex  to stack
	//which store the result
	stk.push(v);
}


void Graph::topologicalSort(){
	vector<bool>visited(V);
	stack<int>stk;
	for(int i=0;i<V;i++) visited[i]=false;

	//call the recursive helper function to store topologicalsort starting from
	//all vertices one by one

	for(int i=0;i<V;i++){
		if(!visited[i]){
			topologicalSortUtil(i,visited,stk);
		}
	}

	//after this print the content of the stack

	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
}



int main(){
	Graph g(6);

	g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

     g.topologicalSort();

     return 0;
}

