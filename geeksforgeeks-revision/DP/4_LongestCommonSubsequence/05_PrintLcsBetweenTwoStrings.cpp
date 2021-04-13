#include<bits/stdc++.h>
using namespace std;
void printLcsBetweenTwoString(string s1,string s2){
	int m=s1.length();
	int n=s2.length();
	int dp[m+1][n+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
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
	int index=dp[m][n];
	//we can also use c style string
	//char charArray[index+1];
	//charArray[index]='\0';
	string s="";
	int i=m;
	int j=n;
	while(i&&j){
		if(s1[i-1]==s2[j-1]){
			//charArray[index-1]=s1[i-1];
			//index--;
			s+=s1[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
          i--;
		}
		else{
			j--;
		}
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
int main(){
    printLcsBetweenTwoString("subhrajyoti","subhra");
}