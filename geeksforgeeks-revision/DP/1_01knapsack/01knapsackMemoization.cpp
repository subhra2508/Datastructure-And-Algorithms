#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int weight,int n){
	int dp[n+1][weight+1];
	memset(dp,-1,sizeof(dp));
	if(n==0||weight==0)return 0;
	if(dp[n][weight]!=-1){
		return dp[n][weight];
	}
	if(wt[n-1]<=weight){
		return dp[n][weight]=max(val[n-1]+knapsack(wt,val,weight-wt[n-1],n-1),knapsack(wt,val,weight,n-1));
	}
	else {
		return dp[n][weight]=knapsack(wt,val,weight,n-1);
	}
	return dp[n][weight];
}
int main(){
int wt[]={1,3,4,5};
  int val[]={1,4,5,7};
  int weight=10;
  int n=4;
  cout<<knapsack(wt,val,weight,n)<<endl;
}