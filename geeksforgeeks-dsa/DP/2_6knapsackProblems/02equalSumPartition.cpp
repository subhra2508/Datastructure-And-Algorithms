// Partition problem is to determine whether a 
// given set can be partitioned into two subsets such that 
// the sum of elements in both subsets is the same. 
//
#include<bits/stdc++.h>
using namespace std;
bool subSetSum(int arr[],int n,int sum){
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j==0){
              dp[i][j]=true;
			}
			if(i==0){
				dp[i][j]=false;
			}
		}
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
	int arr[]={2,3,5,7,8,11};
	int n=6;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(sum%2!=0){
		cout<<"False"<<endl;
	}
	else{
		// if a sum/2 subset is present than it's confirm that another sum/2 is also there
		bool esum=subSetSum(arr,n,sum/2);
		if(esum){
			cout<<"True"<<endl;
		}
		else{
			cout<<"False"<<endl;
		}
	}
}