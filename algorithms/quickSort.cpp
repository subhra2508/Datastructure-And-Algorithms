//https://www.youtube.com/watch?v=COk73cpQbFQ

//the time comlexity of quicksort is O(n logn) is the best case
//worst case is O(n^2)

int partition(int arr[],int start,int end){
	int pivote=arr[end];
	int p_index=start;
	for(int i=start;i<end;i++){
		if(arr[i]<=pivote){
			swap(arr[i],arr[p_index]);
			p_index++;
		}
	}
	swap(arr[p_index],arr[end]);
	return p_index;
}




void quickSort(int arr[],int start,int end){
	if(start<end){
		int p_index=partition(arr,start,end);
		quickSort(arr,start,p_index-1);
		quickSort(arr,p_index+1,end);
	}
}