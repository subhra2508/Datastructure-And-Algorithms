//problem statement-->
//after multiplication we have to return the min cost of multiplication
//we are given the dimension of the matrix how to put the brackets so that we can get min cost matrix
//find i ,j
//find base condition
//find k loop scheme
//calculate ans for temp ans
int solve(int arr[],int i,int j){
	if(i>=j)return 0;
	int min=INT_MAX;
	for(int k=i;k<j;k++){
		int tempAns = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		if(temp<min){
			min=temp;
		}
	}
	return min;
}