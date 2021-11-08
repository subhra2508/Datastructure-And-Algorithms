// given an array arr[], of size n , find the longest subsequence such that difference between adjacent
// element is one .

// this problem is based on longest increasing subsequence



class solution {
public:
	int longestSubsequence(int n,int arr[]){
		//initialize the dp[] array with 1 as a 
		//single element will be of 1 length
		int dp[n];
		for(int i=0;i<n;i++){
			dp[i]=1;
		}
		//start traversing the given array
		for(int i=1;i<n;i++){
			//compare with all the previous elements
			for(int j=0;j<i;j++){
				// if the element is consecutive then 
				//consider this subsequence and update
				//dp[i] is required
				if(arr[i] == arr[j]-1 || arr[i]-1 == arr[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}

			}
		}
		//longest length will be the maximum value
		// of dp array
		int result = 1;
		for(int i=0;i<n;i++){
			if(result < dp[i]){
				result = dp[i];
			}
		}
		return result;
	}
}