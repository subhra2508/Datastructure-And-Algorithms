#include<bits/stdc++.h>
using namespace std;
int LCSMinInsert(string s1,string s2){
	...
	return dp[n][m];
}
int main(){
	string s1="subhrajyoti";
	string s=s1;
	reverse(s1.begin(),s1.end());
	s2=s1;
	int x=LCSMinInsert(s,s2);
	int insertLen=s1.length()-x;
	cout<<insertLen<<endl;
}