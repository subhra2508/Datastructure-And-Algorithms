// dijkstra single source shortest path algorithm


//1. create a set sptset(shortest path tree set) that keep track of vertices included in the shortest-path tree,i.e whose minimum distance from the source
// is calculated and finilized.Initially,this set is empty

//2.assign a distance value to all vertices in the input graph.Initialize all distance values as INFINITY . Assign distance value as 0 for the source,
// vertex so that it is picked first.

//3. while sptset doesn't include all vertices
        //a.pick a vertex u which is not there in sptset and has minimum distance value .
        //b.include u to sptset
        //c. update distance value of all adjacent vertices of u. To update the distance values,iterate
        //through all adjacent vertices.For every adjacent vertex v,if the sum of distance value of u(from source)
        //and weight of edge u-v,is less than the distance value of v, then update the distance value of v.
        

// algorithm 

#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[],bool sptSet[]){
    int min = INT_MAX,min_index;
    for(int v= 0;v<V;v++){
        if(sptSet[v] == false && dist[v]<=min){
            min=dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]){
    cout<<"vertex \t Distance from source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V],int src){
    int dist[V]; // the output array. dist[i] will hold the shortest distance from src to i 
    
    //sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    bool sptSet[V];
    
    //Initialize all distances as Infinity and sptSet[] as false
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    
    //distance from source vertex from itself is zero
    dist[src] = 0;
    
    //find shortest path for all vertices
    for(int count=0;count < V-1;count++){
        
        //pick the minimum distance vertex from the set of vertices not
        //yet processed. u is always equal to src in the first iteration
        int u = minDistance(dist,sptSet);
        
        //mark the picked vertex as processed
        sptSet[u]=true;
        
        //update dist value of the adjacent vertices of the picked vertex
        for(int v=0;v<V;v++){
            
            //update dist[v] only if is not in sptSet, there is an edge from u to v,and total weight of path from src to v
            //through u is smaller than current value of dist[v]
            if(!sptSet[v] && graph[u][v] && dist[u] !=INT_MAX && dist[u]+graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            } 
        }
        printSolution(dist);
    }
}



int main(){
     /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}




















