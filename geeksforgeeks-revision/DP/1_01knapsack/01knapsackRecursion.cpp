#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int weight,int n){
	if(n==0||weight==0)return 0;
	if(wt[n-1]<=weight){
		return (val[n-1]+knapsack(wt,val,weight-wt[n-1],n-1));
	}
	else{
		return knapsack(wt,val,weight,n-1);
	}
}
int main(){
  int wt[]={1,3,4,5};
  int val[]={1,4,5,7};
  int weight=10;
  int n=4;
  cout<<knapsack(wt,val,weight,n)<<endl;
}