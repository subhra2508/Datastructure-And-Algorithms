#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	char ch;
	while(t--){
	    string s;
	    cin>>s;
	    string str="";
	     int hash[123]={0};
	     for(int i=0;i<s.length();i++){
	         if(hash[s[i]]==0){
	             hash[s[i]]=1;
	             str +=s[i];
	         }
	     }
	    cout<<str<<endl;
	}
	return 0;
}