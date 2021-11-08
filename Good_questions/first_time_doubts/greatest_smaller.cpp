#include<bits/stdc++.h>
using namespace std;
int main(){
	 int arr[5]={2,3,4,5,1};
	 set<int>s;
	  for(int i=0;i<5;i++){
	  	 int x=arr[i];
	  	 s.insert(x);
	  	 auto itr=s.lower_bound(x);
	  	 cout<<"the lower_bound is :"<<*itr<<endl;
	  	 if(itr==s.begin()){
	  	 	cout<<-1<<" ";
	  	 }else{
	  	 	itr--;
	  	 	 
	  	 	cout<<*itr<<" ";

	  	 }
	  	 cout<<endl;
	  }	  
}