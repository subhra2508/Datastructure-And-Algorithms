
// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.






class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>path;
        dfs(graph,result,path,0);
        return result;
        
    }
    void dfs(vector<vector<int>>&graph,vector<vector<int>>& result,vector<int>&path,int u){
        path.push_back(u);
        if(u==graph.size()-1)result.push_back(path);
        else{
            for(int v:graph[u]) dfs(graph,result,path,v);
        }
        path.pop_back();
    }
};