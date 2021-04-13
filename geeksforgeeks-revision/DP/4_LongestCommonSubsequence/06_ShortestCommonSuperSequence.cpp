 #include<bits/stdc++.h>
using namespace std;
int LCS(string s1,string s2,int n,int m){
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
int shortestCommonSupersequence(string s1,string s2){
	int n=s1.length();
	int m=s2.length();
	int total=n+m;
	return total-LCS(s1,s2,n,m);
}
int main(){
	string s1="geek";
	string s2="eke";
	cout<<shortestCommonSupersequence(s1,s2)<<endl;
}