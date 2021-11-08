#include<bits/stdc++.h>
using namespace std;
int LCS(int x[],int y[],int n,int m){
	if(n==0||m==0){
		return 0;
	}
	if(x[n-1]==y[m-1]){
		return 1+LCS(x,y,n-1,m-1);
	}
	else{
		return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
	}
}
int main(){
	int x[]={1,2,3,4,5,6};
	int y[]={4,5,6,7};
	cout<<LCS(x,y,6,4)<<endl;
} 