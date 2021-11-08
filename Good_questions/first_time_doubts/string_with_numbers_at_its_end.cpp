#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int last_index=str.find_last_not_of("0123456789");
	    string result=str.substr(last_index+1);
	    stringstream geek(result);
	    int x=0;
	    geek>>x;
	    if(x==last_index+1){
	        cout<<1<<endl;
	    }
	    else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}