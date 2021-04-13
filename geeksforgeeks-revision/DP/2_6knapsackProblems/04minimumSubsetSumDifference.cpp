#include<bits/stdc++.h>
using namespace std;//38.55
//in subset sum problem we can either take it or not ,if it is less than sum and the subset making the desire sum but in
//minimum subset sum we have to take the subset if the subset sum is equal to range of the array
int findMin(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
        dp[i][0]=true;
	}
	for(int j=1;j<sum+1;j++){
		dp[0][j]=false;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int diff=INT_MAX;
	for(int j=sum/2;j>=0;j--){
		if(dp[n][j]==true){
			diff=sum-2*j;
			break;
		}
	}
	return diff;

}
int main(){
   int arr[]={3,1,4,2,2,1};
   int n=6;
   cout<<findMin(arr,6);
}