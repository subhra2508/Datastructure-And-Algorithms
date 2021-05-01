
// Given two strings X and Y, print the
// shortest string that has both X and Y as subsequences. 
// If multiple shortest supersequence exists, print any one of them.

// example -->

// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB" 
// OR Any string that represents shortest
// supersequence of X and Y





#include<bits/stdc++.h>
using namespace std;
string LCS(string s1,string s2){
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
	int index=dp[n][m];
	int i=n;
	int j=m;
	string s="";
	while(i&&j){
		if(s1[i-1]==s2[j-1]){
			s+=s1[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			s+=s1[i-1];
			i--;
		}
		else{
			s+=s2[j-1];
			j--;
		}
	}
	while(i){
		s+=s1[i-1];
		i--;
	}
	while(j){
		s+=s2[j-1];
		j--;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	string s1="AGGTAB";
	string s2="GXTXAYB";
    cout<<LCS(s1,s2)<<endl;
}