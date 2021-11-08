class solution{
public:
	int maxSum(int N,vector<vector<int>>mat){
		int incl = max(mat[0][0],mat[1][0]);
		int excl = 0;
		int excl_new;
		for(int i=0;i<N;i++){
			int excl_new = max(incl,excl);
			incl = excl+max(mat[0][i],mat[1][i]);
			excl = excl_new;
		}
		return max(excl,incl);
	}
};