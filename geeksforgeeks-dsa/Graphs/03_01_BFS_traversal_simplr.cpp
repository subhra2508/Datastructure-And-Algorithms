class solution {
    public:
    vector<int>bfsOfGraph(int V , vector<int> adj[]){
        int visited[n] = {0};
        visited[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push(node);

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