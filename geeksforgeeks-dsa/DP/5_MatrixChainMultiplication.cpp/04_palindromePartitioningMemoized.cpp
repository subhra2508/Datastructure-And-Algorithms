#include<bits/stdc++.h>
using namespace std;
static int dp[1001][1001];
bool isPalindrome(string s,int i,int j){
	while(i<j){
		if(s[i]!=s[j])return false;
		i++;
		j--;
	}
	return true;
}
int solve(string s,int i,int j){
	if(i>=j||isPalindrome(s,i,j))return 0;
    int ans=INT_MAX;
    int count;
    for(int k=i;k<j;k++){
    	count=solve(s,i,k)+solve(s,k+1,j)+1;
    	ans=min(ans,count);
    }
    return dp[i][j]=ans;
}
int main(){
   string str="ababbbabbababa";
   int i=0;
   int j=str.length()-1;
   memset(dp,-1,sizeof(dp));
   cout<<solve(str,i,j);
}