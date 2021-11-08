#include<bits/stdc++.h>
using namespace std;
class minheap{
	int *harr;
	int capacity;
	int heap_size;
public:
	minheap(int *arr,int capacity);
	void heapify(int);
	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return(2*i+1);
	}
	int right(int i){
		return (2*i)+2;
	}
	int extractmin();
	int getmin(){
		return harr[0];
	}
	int getsize(){
		return heap_size;
	}
	void insertkey(int k);
};
void minheap::insertkey(int k){
	heap_size++;
	int i=heap_size-1;
	harr[i]=k;
	while(i!=0&&harr[parent(i)]>harr[i]){
		swap(harr[i],harr[parent(i)]);
		i=parent(i);
	}

}
int minheap::extractmin(){
	if(heap_size<=0){
		return INT_MAX;
	}
	if(heap_size==1){
		heap_size--;
		return harr[0];
	}
	int root=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	heapify(0);
	return root;
}
void minheap::heapify(int i){
	int smallest=i;
	int l=left(i);
	int r=right(i);
	if(l<heap_size&&harr[l]<harr[parent(i)])
		smallest=l;
	if(r<heap_size&&harr[r]<harr[parent(i)])
		smallest=r;
	if(smallest!=i){
		swap(harr[i],harr[smallest]);
		heapify(smallest);
	}
}
int countminops(int arr[],int n,int k){
	minheap h(arr,n);
	long int res=0;
	while(h.getmin()<k){
		if(h.getsize()==1)return -1;
		int first=h.extractmin();
		int second=h.extractmin();
		h.insertkey(first+second);
		res++;
	}
	return res;
}
int main() 
{ 
    int arr[] = {1, 10, 12, 9, 2, 3}; 
    int n  = sizeof(arr)/sizeof(arr[0]); 
    int k = 6; 
    cout <<countminops(arr, n, k)<<endl; 
    return 0; 
} 
