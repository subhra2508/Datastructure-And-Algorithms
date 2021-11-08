#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int solve(int arr[],int i,int j){
   if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
   dp[i][j]=INT_MAX;
 for(int k=i;k<j;k++){
 	dp[i][j]=min(dp[i][j],solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]));
 }
  return dp[i][j];

}
int main(){
	int arr[]={1,2,3,4};
	memset(dp,-1,sizeof(dp));
	cout<<solve(arr,1,3)<<endl;
}