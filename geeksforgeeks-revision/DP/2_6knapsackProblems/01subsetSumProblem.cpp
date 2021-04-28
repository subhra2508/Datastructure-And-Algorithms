// Given a set of non-negative integers,
// and a value sum, determine if there is a subset of the given set with sum equal to given sum.
#include<bits/stdc++.h>
using namespace std;
int subsetSum(int arr[],int sum,int n){  
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		 dp[i][0]=1;
	}
	for(int j=1;j<sum+1;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i]<=j){
		        dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
	        }
	        else{
		         dp[i][j]=dp[i-1][j];
	        }
		}
	}
	return dp[n][sum];
}
int main(){
	int arr[]={2,3,4,5,8,10};
	cout<<subsetSum(arr,11,6)<<endl; 
}