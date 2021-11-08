//insertion sort
for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0&&arr[j]>key){
    	arr[j+1]=arr[j];
    	j=j-1;
    }
    arr[j+1]=key;
}
//merge sort its an divide and conqure algorithm
//merge sort
void merge(int arr[],int l,int m,int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	 for(j=0;j<n2;j++){
	 	R[j]=arr[m+1+j];
	 }
	 i=0;j=0;k=l;
	 while(i<n1&&j<n2){
	 	if(L[i]<=R[j]){
	 		arr[k]=L[i];
	 		i++;
	 	}else{
	 		arr[k]=R[j];
	 		j++;
	 	}
	 	k++;
	 }
	 while(i<n1){
	 	arr[k]=L[i];
	 	i++;
	 	k++;
	 }
	 while(j<n2){
	 	arr[k]=R[j];
	 	j++;
	 	k++;
	 }
}
void mergesort(int arr[],int l ,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
//quick sort algorithm
//it is also a  divide conqure algorithm which follow divide
//and conqure strategy
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int Pindex=low;
	for(int j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			swap(arr[j],arr[Pindex]);
			Pindex=Pindex+1;
		}
	}
		swap(arr[Pindex],arr[high]);
		return Pindex;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
//selection sort
void selectionsort(int arr[],int n){
	int i,j,min_index;
	for(i=0;i<n-1;i++){
		min_index=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min_index])
				{
					min_index=j;
				}	
		}
		swap(arr[min_index],arr[i]);
	}
}