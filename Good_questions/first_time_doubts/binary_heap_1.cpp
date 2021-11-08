heapify(int arr[],int n,int i){
	int largest =i;//0
	int left =(2*i)+1;//1
	int right=(2*i)+2;//2
	if(left<n&&arr[left]>arr[largest]){
	largest = left;
	}
	if(right<n&&arr[right]>arr[largest]){
	largest = right;
	}
	if(largest ! = i){
	swap(arr[i],arr[largest]);
	heapify(arr,n,largest);
	}
}
class MinHeap{
	int *harr;
	int capacity;
	int heap_size;
	public:
	MinHeap(int capacity);
	void heapify(int );
	int parent(int i){return (i-1)/2;}
	int left(int i){return (2*i)+1;}
	int right(int i){return (2*i)+2;}
	int extractMin();
	void decreaseKey(int i,int new_val);
	int getMin(){return harr[0];}
	void deleteKey(int i);
	void insertKey(int k);
};
void MinHeap::MinHeap(int cap){
	heap_size=0;
	capacity=cap;
	harr = new int[cap];
	//int harr[cap];
}
void MinHeap::insertKey(int k){
if(heap_size==capacity){
cout<<"overflow can't insertKey"<<endl;}
   heap_size++;
   int i = heap_size-1;
   harr[heap_size-1]=k;
   //min property
   while(i!=0 && harr[parrent(i)]>harr[i]){
   swap(harr[i],harr[parent(i)]);
   i = parent(i);
   }
}
//decrease the elements on the heap
void MinHeap::decreaseKey(int i,int new_val){
	harr[i]=new_val;
	while(i!=0&&harr[parent(i)]>harr[i]){
	swap(harr[parent(i)],harr[i]);
	i = parent(i);
	}
}
int MinHeap::extractMin(){
	if(heap_size<=0){
	return INT_MAX;
	}
	if(heap_size == 1){
	 heap_size--;
	 return harr[0];
	}
	int root=harr[0];
	harr[0]=harr[heap_size-1];
	heap_size--;
	minHeapify(0);
	return root;
}
void MinHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}
void MinHeap::MinGeapify(int i){}