//count the number of subset of given sum present in the array
#include<bits/stdc++.h>
using namespace std;
int countSubsetSum(int arr[],int n,int sum){
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j==0){
				dp[i][j]==0;
			}
			if(i==0){
				dp[i][j]=1;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
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
	cout<<countSubsetSum(arr,11,6)<<endl; 
}