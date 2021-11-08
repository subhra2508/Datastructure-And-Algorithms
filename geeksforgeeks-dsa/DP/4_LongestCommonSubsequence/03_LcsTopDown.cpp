#include<bits/stdc++.h>
using namespace std;
int LCS(int x[],int y[],int n,int m){
      int dp[n+1][m+1];
      for(int i=0;i<n+1;i++){
      	for(int j=0;j<m+1;j++){
             if(i==0||j==0){
             	dp[i][j]=0;
             }
             else if(x[i-1]==y[j-1]){
             	dp[i][j]=dp[i-1][j-1]+1;
             }
             else{
             	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
      	}
      }
      return dp[n][m];
}
int main(){
    int x[]={1,2,3,4,5,6};
	int y[]={4,5,6,7};
	cout<<LCS(x,y,6,4)<<endl;
}
