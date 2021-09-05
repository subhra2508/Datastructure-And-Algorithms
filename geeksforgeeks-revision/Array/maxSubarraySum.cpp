
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
// i guess this is easy right ???
int kadane(int arr[], int n)
{
    // stores the maximum sum subarray found so far
    int max_so_far = 0;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
 
        max_ending_here = max(max_ending_here, 0);
 
        max_so_far = max(max_so_far, max_ending_here);
    }
 
    return max_so_far;
}