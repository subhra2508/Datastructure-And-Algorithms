#include<bits/stdc++.h>
using namespace std;
int countOfSubsetSum(int arr[],int n,int sum){
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int j=1;j<sum+1;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
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
   int arr[]={1,1,2,3};
   int sumOfArray=7;
   int diff=2;
   int sum=(diff+sumOfArray)/2;
   int sizeOfArray=4;
   cout<<countOfSubsetSum(arr,sizeOfArray,sum);
}