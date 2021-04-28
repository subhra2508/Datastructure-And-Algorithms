// Given a set of integers, the task is to divide it into two sets S1 
// and S2 such that the absolute difference between their sums is minimum. 
// If there is a set S with n elements, then if we assume Subset1 has m elements,
// Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.



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
				dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int diff=INT_MAX;
	for(int j=sum/2;j>=0;j--){
		if(dp[n][j]==true){
			diff=sum-2*j;//from sum/2 to 0 becoz we need to minimize (range-2s1) so we need to max s1
			break;
		}
	}
	return diff;

}
int main(){
   // int arr[]={3,1,4,2,2,1};
   int arr[]={1, 6, 11, 5};
   int n=4;
   cout<<findMin(arr,4);
}