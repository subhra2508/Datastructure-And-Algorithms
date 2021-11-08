#include<bits/stdc++.h>
using namespace std;
int rodCutting(int price[],int n){
	 int val[n+1];
	 val[0]=0;
	 int i,j;
	 for(int i=1;i<=n;i++){
	 	int max_val=INT_MIN;
	 	for(int j=0;j<i;j++){
	 		max_val=max(max_val,price[j]+val[i-j-1]);	
	 	}
	 	val[i]=max_val;
	 }
	 return val[n];
}
int main(){
	int 
}


//recursive solution
int rodCutRecursive(int price[],int n){
	if(n==0)return 0;
	int max_val=INT_MIN;
	for(int i=0;i<n;i++){
		max_val=(max_val,p[i]+rodCutRecursive(p,n-i));
	}
	return max_val;
}