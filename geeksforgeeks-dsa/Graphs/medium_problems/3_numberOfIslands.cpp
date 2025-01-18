//number of island

class solution {
    private:
    void bfs(int row, int col , vector<vector<int>>vis,vector<vector<char>>&grid){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        temp_row = q.front().first;
        temp_col = q.front().second;
        q.pop();

        for(int delrow = -1 ;delrow <=1;delrow++){
            for(int delcol = -1;delcol <=1;delcol++){
                int nrow = temp_row + delrow;
                int ncol = temp_col + delcol;
                if(nrow >=0 && nrow < n && mcol >=0 && mrow < m && !vis[nrow][mcol] && grid[nrow][mcol] == '1'){
                    vis[nrow][mcol] = 1;
                    q.push({nrow,mcol});
                }
            }
        }


        }
    }
    public:
    int numIslands(vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){

                    bfs(i,j,vis,grid);
                    count ++;
                }
            }
        }
        return count;
    }
}

//sc -> O(n^2)
// tc -> O(n^2)