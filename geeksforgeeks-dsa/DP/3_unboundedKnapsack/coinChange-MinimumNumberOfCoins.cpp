#include<bits/stdc++.h>
using namespace std;
//minimum numbers of coins required to make sum 5
int coinChangeMin(int coin[],int amt,int n){
	int dp[n+1][amt+1];
	for(int i=0;i<amt+1;i++){
		dp[0][i]=INT_MAX;
	}
	for(int i=0;i<n+1;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<amt+1;j++){
			if(coin[i-1]<=j){
				dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
    return dp[n][amt]>=INT_MAX?-1:dp[n][amt];
}
//recursive
// min(1+count(coins,amt-coins[i],i),cout(coins,amt,i-1))
int main(){
int coin[]={1,2,3};
     int n=3;
     int amt=5;
     cout<<coinChangeMin(coin,amt,n)<<endl;
}
//https://www.youtube.com/watch?v=ZI17bgz07EE