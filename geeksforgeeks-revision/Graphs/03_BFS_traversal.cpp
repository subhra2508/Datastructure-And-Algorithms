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
Graph:Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph:addEdge(int v,int w){
	
}
int main(){

}