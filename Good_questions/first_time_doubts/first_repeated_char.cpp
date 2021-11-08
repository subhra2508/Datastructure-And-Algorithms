#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int flag=0;
	    unordered_map<char,int>mp;
	    for(int i=0;i<s.size();i++){
	        if(flag==0&&mp.count(s[i])!=0){
	            flag=1;
	            cout<<s[i]<<endl;
	        }
	        mp[s[i]]++;
	}
	if(flag==0)
	cout<<-1<<endl;
	    
	}
	return 0;
}