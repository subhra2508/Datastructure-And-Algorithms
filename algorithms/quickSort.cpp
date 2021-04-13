//https://www.youtube.com/watch?v=COk73cpQbFQ


int partition(int arr[],int start,int end){
	pivote=arr[end];
	partition_index=arr[start];
	for(int i=start;i<end;i++){
		if(arr[i]<=pivote){
			swap(arr[i],partition_index);
			partition_index++;
		}
	}
	swap(arr[partition_index],arr[end]);
	return partition_index;
}




void quickSort(int arr[],int start,int end){
	if(start<end){
		int p_index=partition(arr,start,end);
		quickSort(arr,start,p_index-1);
		quickSort(arr,p_index+1,end);
	}
}