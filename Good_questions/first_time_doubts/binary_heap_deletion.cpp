#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
	int largest=i;
	int left=(2*i)+1;
	int right=(2*i)+2;
	if(largest<n&&arr[left]<arr[largest]){
		largest=left;
	}
	if(largest<n&&arr[right]<arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void deleteNode(int arr[],int &n){
	int lastElement=arr[n-1];
	arr[0]=lastElement;
	n=n-1;
	heapify(arr,n,0);
}
int main(){

}