// Given a binary array arr of size N and an integer M . 
//Find the maximum number of consecutive 1's produced by flipping at most M 0's.


int findZeros(int arr[],int n,int m){
	int wl = 0;
	int wr = 0;

	//left index and size of the widest window
	int bestL = 0;//left index
	bestWindow = 0;//size of the widest window
	int zeroCount = 0;
	while(wr < n){
		if(zeroCount <= m){
			if(arr[wr] == 0){
				zeroCount++;
			}
			wr++;
		}
		if(zeroCount > m){
			if(arr[wl] == 0){
				zeroCount--;
			}
			wl++;
		}
		//update widest window if this window size is more
		if(wr-wl > bestWindow && zeroCount <= m){
			bestWindow = wr-wl;
			bestL = wl;
		}
	}
	//print the position of zeros in the widest window
	for(int i=0;i<bestWindow;i++){
		if(arr[bestL+i] == 0){
			cout<<bestL+i<<" ";
		}
	}
	return bestWindow;

}
