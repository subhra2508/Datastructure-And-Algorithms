"
for searching for minimum element:
	
int binarySearch(int arr[],int start_index,int end_index){
    if(arr.length()==1){
        return arr[start_index];
    }
    if(arr[end_index]>arr[start_index]){
        return arr[start_index];
    }
    while(start_index<=end_index){
        int mid_index=start_index+(end_index-start_index)/2;
        if(start_index<mid_index&&arr[mid_index]<arr[mid_index-1]){
            return arr[mid_index];
        }
        else if(end_index>mid_index&&arr[mid_index]>arr[mid_index+1]){
            return arr[mid_index+1];
        }
        else if(arr[end_index]>arr[mid_index]){
            end_index=mid_index-1;
        }
        else{
            start_index=mid_index+1;
        }
    }
}
"