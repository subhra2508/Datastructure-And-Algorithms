#include<bits/stdc++.h>
using namespace std;
 int dp[1001][1001];
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
    int left,right;
    for(int k=i;k<j;k++){
    	// count=solve(s,i,k)+solve(s,k+1,j)+1;//not optimized
      if(dp[i][k]!=-1){
        left=dp[i][j];
      }
      else{
        left=solve(s,i,k);
        dp[i][k]=left;
      }
      if(dp[k+1][j]!=-1)right=dp[k+1][j];
      else{
         right=solve(s,k+1,j);
         dp[k+1][j]=right;
      }
      count=1+left+right;
      ans=min(ans,count);

    }
    return ans;
}
int main(){
   string str="ababbbabbababa";
   int i=0;
   int j=str.length()-1;
   memset(dp,-1,sizeof(dp));
   cout<<solve(str,i,j);
}