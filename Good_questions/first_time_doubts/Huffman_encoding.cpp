#include<bits/stdc++.h>
using namespace std;
#define MAX_TREE_HT 100
struct MinHeapNode{
	char data;
	unsigned freq;
	struct MinHeapNode *left ,*right;
};
struct MinHeap{
	unsigned size;
	unsigned capacity;
	struct MinHeapNode**array;
};
struct MinHeapNode*newNode(char data,unsigned freq){
	struct MinHeapNode*temp=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    return temp;	
}
struct MinHeap*createMinHeap(unsigned capacity){
	struct MinHeap*minheap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    minheap->size=0;
    minheap->capacity=capacity;
    minheap->array=(struct MinHeapNode**)malloc(minheap->capacity*sizeof(struct MinHeapNode*));
    return minheap;	
}
void minHeapify(struct MinHeap*minHeap ,int index){
	int smallest=index;
	int left=2*index+1;
	int right=2*index+2;
	if(left<minHeap->size&&minHeap->array[left]->freq<minHeap->array[smallest]->freq)
		smallest=left;
	if(right<minHeap->size&&minHeap->array[right]->freq<minHeap->array[smallest]->freq)
		smallest=right;
	if(smallest!=index){
		swap(minHeap->array[smallest],minHeap->array[index]);
		minHeapify(minHeap,smallest);
	}
}

int isSizeOne(struct MinHeap*minHeap){
	return(minHeap->size==1);	
}

struct MinHeapNode*extractMin(struct MinHeap*minHeap){
	struct MinHeapNode*temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	--minHeap->size;
	minHeapify(minHeap,0);
	return temp;
}

void insertMinHeap(struct MinHeap*minHeap,struct MinHeapNode*minHeapNode){
	++minHeap->size;
	int i=minHeap->size-1;
	while(i&&minHeapNode->freq < minHeap->array[(i-1)/2]->freq){
		minHeap->array[i]=minHeap->array[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->array[i]=minHeapNode;
}

