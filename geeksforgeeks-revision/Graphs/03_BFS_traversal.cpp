#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;//no of vertices
	//pointer to an array containing adjacency
	//lists
	list<int>*adj;
public:
	Graph(int V);//constructor
	void addEdge(int v,int w); //function to add an edge to graph
	void BFS(int s); //prints BFS traversal from a given source s
};

//constructor
Graph:Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}


//function to add an edge to graph
void Graph:addEdge(int v,int w){
	add[v].push_back(w);//add w to v's list.
}


//prints BFS traversal from a given source s
void Graph:BFS(int s){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visisted[i]=false;
	}

	list<int>queue;
	// Mark the current node as visited and enqueue it
	visited[s] = true;
	 queue.push_back(s);

	 //'i' will be used to get all adjacent vertices of a vertex
	 list<int>::iterator i;

	 while(!queue.empty()){
	 	s=queue.front();
	 	cout<<s<<" ";
	 	queue.pop_front();

	 	//Get all adjacent vertices of the dequeued vertex s.
	 	// if a adjacent has not been visited, then mark it visited
	 	// and enqueue it
	 	for(i = adj[s].begin();i!=adj[s].end();i++){
	 		if(!visited[*i]){
	 			visited[*i]=true;
	 			queue.push_back(*i);	
	 		}
	 	}
	 }
}



int main(){
 Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}