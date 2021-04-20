#include<bits/stdc++.h>
using namespace std;
int static dp[100][100];
int solve(int e,int f){
    if(f==0||f==1)return f;
    if(e==1)return f;
    if(dp[e][f]!=-1)return dp[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
    	int temp=1+max(solve(e-1,k-1),solve(e,f-k));
    	mn=min(temp,mn);
    }
    return dp[e][f]=mn;
}
//more optimize code
int solve(int e,int f){
    if(f==0||f==1)return f;
    if(e==1)return f;
    if(dp[e][f]!=-1)return dp[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
    	int low,high;
    	if(dp[e-1][k-1]!=-1)
    		low =dp[e-1][k-1];
    	else{
    		low = solve(e-1,k-1);
    		dp[e-1][k-1] = low;
    	}
    	if(dp[e][f-k]!=-1)
    		high = dp[e][f-k];
    	else{
    		high = solve(e,f-k);
    		dp[e][f-k] = high;
    	}
    	int temp=1+max(low,high);
    	mn=min(temp,mn);
    }
    return dp[e][f]=mn;
}



int main(){
	int e=2;
	int f=10;
  memset(dp,-1,sizeof(dp));
  cout<<solve(e,f);
}