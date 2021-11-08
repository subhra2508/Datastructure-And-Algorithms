// Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
// The task is to remove/delete and insert the minimum
// number of characters from/in str1 to transform it into str2. It could be possible
// that the same character needs to be removed/deleted from one point of 
// str1 and inserted to some another point.

// example -->
// Input : 
// str1 = "heap", str2 = "pea" 
// Output : 
// Minimum Deletion = 2 and
// Minimum Insertion = 1


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
void minNumInsertionAndDeletion(string s1,string s2){
	int n=s1.length();
	int m=s2.length();
	int deletion=n-LCS(s1,s2,n,m);
	int insertion=m-LCS(s1,s2,n,m);
	cout<<"Insertion = "<<insertion<<endl;
	cout<<"Deletion = "<<deletion<<endl;
}
int main(){
   minNumInsertionAndDeletion("heap","sankar");
}