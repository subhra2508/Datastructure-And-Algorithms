#include<bits/stdc++.h>
using namespace std;
int maximumCoinChange(int coin[],int amt,int n){
	int dp[n+1][amt+1];
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int j=0;j<amt+1;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<amt+1;j++){
			if(coin[i-1]<=j){
				dp[i][j]=(dp[i][j-coin[i-1]]+dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
    return dp[n][amt];
}

int main(){
     int coin[]={1,2,3,4};
     int n=4;
     int amt=5;
     cout<<maximumCoinChange(coin,amt,n)<<endl;
}
