#include<bits/stdc++.h>
using namespace std;
void printSubstring(string str,int low,int high){
	for(int i=low;i<=high;i++){
		cout<<str[i];
	}
	cout<<endl;
}
int LPS(string str){
	int n=str.size();
	bool dp[n][n];
	 
 
	memset(dp,0,sizeof(dp));
	int maxlength=1;
	for(int i=0;i<n;i++){
		dp[i][i]=true;
	}
	int start=0;
	for(int i=0;i<n-1;i++){
		if(str[i]==str[i+1]){
			dp[i][i+1]=true;
			start=i;
			maxlength=2;
		}
	}
	for(int k=3;k<=n;k++){
		for(int i=0;i<n-k+1;i++){
			int j=i+k-1;
			if(dp[i+1][j-1]&&str[i]==str[j]){
				dp[i][j]=true;
				if(k>maxlength){
					start=i;
					maxlength=k;
				}
			}
		}
	}
	printSubstring(str,start,start+maxlength-1);
	return maxlength;

}
int main(){
	string str="babad";
	cout<<LPS(str)<<endl;

}