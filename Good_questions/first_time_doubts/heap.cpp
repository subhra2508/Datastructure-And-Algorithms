#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
	int largest=i;
	int l=i*2+1;
	int r=i*2+2;
	if(l<n&&arr[l]>arr[largest])
		largest=l;
	if(r<n&&arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
		swap(arr[i],arr[largest])
	heapify(arr,n,largest);
}
void deleteRoot(int arr[],int &n){
	int lastelement=arr[n-1];
	arr[0]=lastelement;
	n=n-1;
	heapify(arr,n,0);
}
void heapify_for_insertion(int arr[],int n,int i){
	int parent=(i-1)/2;
	if(arr[parent]>0){
		if(arr[i]>arr[parent]){
			swap(arr[i],arr[parent]);
		}
		heapify(arr,n,parent);
	}
}
void insertNode(int arr[],int &n,int key){
	n=n+1;
	arr[n-1]=key;
	heapify_for_insertion(arr,n,n-1);
}