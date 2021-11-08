#include<bits/stdc++.h>
using namespace std;
int main(){
	 string str;
	 str="subhrajyotisankarsau";
	 string patt="jac";
	 int min_index=INT_MAX;
	 int flag=0;
	 unordered_map<char,int>mp;
	 for(int i=0;i<str.size();i++){
	 	mp.insert({str[i],i});
	 }
	 unordered_map<char,int>::iterator itr;
      for(int i=0;i<patt.size();i++){
          char ch;
          ch=patt[i];
          for(auto itr=mp.begin();itr!=mp.end();itr++){
          	if(ch==itr->first){
          		flag=1;
          		if(min_index > itr->second){
          			min_index=itr->second;
          		}
          	}
          }
      }
      if(flag==0){
      	cout<<"NO character present"<<endl;
      }
      cout<<min_index<<endl;
   
}