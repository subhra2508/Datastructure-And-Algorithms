https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

int findMaxSum(int *arr,int n){
	int incl = arr[0];
	int excl = 0;
	int excl_new;
	for(int i=1;i<n;i++){
		// current max including i
		excl_new = incl>excl?incl:excl;

		//current max including i,means excl + current ele 
		incl = arr[i]+excl;
		excl = excl_new;
	}
	return excl > incl ? excl:incl;
}