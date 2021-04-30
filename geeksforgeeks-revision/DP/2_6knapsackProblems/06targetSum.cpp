//
/*
Target Sum Problem
Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
*/
#include<bits/stdc++.h>
using namespace std;
int targetSum(int arr[],int n,int sum){
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
  int arraySize=4;
  //int sum=2;
  int diff=2;
  int arrayRange=7;
  int sum =( diff+arrayRange)/2;//sum1-sum2=diff//sum1+sum2=range//2sum1=range+diff//
  cout<<targetSum(arr,arraySize,sum)<<endl;
}