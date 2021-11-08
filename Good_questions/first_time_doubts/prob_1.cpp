#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void load_block(int arr1[],int b,int n,vector<int>&v){
	for(int i=0;i<n;i+b){
        v.push_back(i); 
	}
}
void count_cach_load(int arr[],int arr1[],int n,int m,int b){
	int count=0;
	int i=0;
	 while(i<m){
	 	std::vector<int>v;
	 	load_block(arr1,b,n,v);
	 	count++;
	 	 for(int j=0;j<m;j++){
               int f=arr[j];
               if(binary_search(v.begin(),v.end(),f)){
               	continue;
               }
               else{
               	i=j;
               	break;
               }
	 	 }
	 }
	 cout<<count<<endl;
}
int main(){
	int t;
	while(t--){
		int n,b,m;
		cin>>n>>b>>m;
		//b number of block taken phase wise.
		int arr[m];
		for(int i=0;i<m;i++){
			cin>>arr[i];
		}
		sort(arr,arr+m);
		int arr1[n];
		for(int i=0;i<n;i++){
           arr1[i]=i;
		}
		 count_cach_load(arr,arr1,n,m,b);
	}
}