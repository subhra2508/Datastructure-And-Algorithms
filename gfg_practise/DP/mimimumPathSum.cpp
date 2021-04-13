#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>>target;
	target={{1,2,3},{1,5,1},{4,2,1}};
	cout<<target.size()<<"=rows"<<endl;
	int cols=target[0].size();
	int rows=target.size();
	cout<<target[0].size()<<"=cols"<<endl;
	vector<vector<int>>dp(rows,vector<int>(cols));
	cout<<dp[0][0]<<endl;

}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int rows=grid.size();
        if(rows==0){
            return 0;
        }
        int cols=grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols));
        dp[0][0]=grid[0][0];
        for(int i=1;i<cols;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<rows;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[rows-1][cols-1];
    }
};