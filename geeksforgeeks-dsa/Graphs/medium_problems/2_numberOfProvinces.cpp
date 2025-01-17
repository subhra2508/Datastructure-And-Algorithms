


class solution {
    private:
    void dfs(int node, vector<int>adjLs[],int vis[]){
        vis[node] =1 ;
        for(auto it:adj[node]){
            dfs(it,adj,vis);
        }
    }
    public:
    int numProvinces(vector<vector<int>>adj,int V){
        int vis[V] = {0};
        int start = 0;
        int count = 0;
        vector<int>adjLs[];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjLs,vis);
            }
        }
        return count;
    }
}


//te -> o(n)+o(v+2E)
//sc -> o(n)