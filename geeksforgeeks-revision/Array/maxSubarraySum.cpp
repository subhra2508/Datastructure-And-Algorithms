
//this is called kadane's algorithm


int maxSubarraySum(int arr[],int size){
	int max_so_far = INT_MIN;
	int maxEnd = 0;
	for(int i=0;i<size;i++){
		maxEnd = maxEnd+arr[i];
		if(max_so_far < maxEnd){
			max_so_far=maxEnd;
		}
		if(maxEnd < 0){
			maxEnd = 0;
		}
	}
	return max_so_far;
}