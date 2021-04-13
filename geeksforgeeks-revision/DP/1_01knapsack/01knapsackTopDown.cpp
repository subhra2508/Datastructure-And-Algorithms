#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int w,int n){
	int dp[n+1][w+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			 if(i==0||j==0){
			 	dp[i][j]=0;
			 }
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(wt[i-1]<=j){
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][w];
}
int main(){
  int wt[]={1,3,4,5};
  int val[]={1,4,5,7};
  int weight=10;
  int n=4;
  cout<<knapsack(wt,val,weight,n)<<endl;
}

//this year
// nodejs,reactjs,django,firbase,html,css,js,c++,python,devops,deployment,