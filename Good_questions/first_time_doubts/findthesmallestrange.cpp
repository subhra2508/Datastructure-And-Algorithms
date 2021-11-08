#include<bits/stdc++.h>
using namespace std;
int ptr[501];
pair<int,int>findSmallestRange(int arr[][N],int n,int k){
	pair<int,int>p;
	int minval,maxval,minrange,minel,maxel,flag,minindex;
	for(int i=0;i<=k;i++){
		ptr[i]=0;
	}
	minrange=INT_MAX;
	while(1){
		minindex=-1;
		minval=INT_MAX;
		maxval=INT_MIN;
		flag=0;
		for(int i=0;i<k;i++){
			if(ptr[i]==n){
				flag=1;
				break;
			}
			if(ptr[i]<n&&arr[i][ptr[i]]<minval){
				minindex=i;
				minval=arr[i][ptr[i]];
			}
			if(ptr[i]<n&&arr[i][ptr[i]]>maxval){
				maxval=arr[i][ptr[i]];
			}
		}
		if(flag)break;
		ptr[minindex]++;
		if((maxval-minval)<minrange){
			minel=minval;
			maxel=maxval;
			minrange=maxel-minel;
		}
	}
	p.first=minel;
	p.second=maxel;
	return p;
}
int main(){

}