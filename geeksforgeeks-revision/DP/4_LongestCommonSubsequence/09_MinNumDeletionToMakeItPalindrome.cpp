#include<bits/stdc++.h>
using namespace std;
int LCS();
int main(){
     string s="agbcba";
	 string s1=s;
	 reverse(s1.begin(),s1.end());
	 string s2=s1;
	 int lcslength=LCS(s,s2);
	 cout<<s.length()-lcslength<<endl;
}