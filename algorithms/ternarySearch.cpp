#include<bits/stdc++.h>
using namespace std;
int ternarySearch(int l,int r,int key,int arr[]){
	int mid1=l+(r-l)/3;
	int mid2=l+(r-l)/3;
	if(arr[mid1] == key){
		return mid1;
	}
	if(arr[mid2] == key){
		return mid2;
	}
	if(key < arr[mid1]){
		return ternarySearch(1,mid1-1,key,arr);
	}
	else if(key > arr[mid2]){
		return ternarySearch(mid2+1,r,key,arr);
	}
	else {
		return ternarySearch(mid1+1,mid2-1,key,arr);
	}
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int l = 0;
	int r = 9;
	int key = 5;
	int p = ternarySearch(l,r,key ,arr);
	cout<<p<<endl;
}