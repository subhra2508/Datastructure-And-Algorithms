class solution {
    //breadth first search -> level order traversal
    public:
    //V -> numberOfNodes
    vector<int>bfsOfGraph(int V , vector<int> adj[]){
        //every node on the starting is unvisited
        int visited[V] = {0};

        //starting node
        visited[0]=1;


        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //push the node value to the bfs vector to store it
            bfs.push_back(node);

            //searching on the breadth whichever nodes are connected and 
            //not visited pushed into the queue and the further into the bfs vector
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};