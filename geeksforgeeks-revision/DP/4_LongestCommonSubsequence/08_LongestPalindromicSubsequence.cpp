
//Given a sequence, find the length of the longest palindromic subsequence in it.

#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubsequence(string s1,string s2){
	int n=s1.length();
	int m=s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
int main(){
	 string s="agbcba";
	 string s1=s;
	 reverse(s1.begin(),s1.end());
	 string s2=s1;
	 cout<<LongestCommonSubsequence(s,s2)<<endl;
}