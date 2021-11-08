long long int count(long long int n){
	long long int table[n+1];
	memset(table,0,sizeof(table));
	table[0]=1;
	for(int i=3;i<n+1;i++){
		table[i]+=table[i-3];
	}
	for(int i=5;i<n+1;i++){
		table[i]+=table[i-5];
	}
	for(int i=10;i<n+1;i++){
		table[i]+=table[i-10];
	}
}

class solve{
public:
	void numberOfUniquePath(int a ,int b){
		int dp[a+1][b+1];
		for(int i=0;i<a+1;i++){
			for(int j=0;j<b+1;j++){
				if(i==0|| j==0){
					dp[i][j]=1;
				}
				else{
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				}
			}
		}
		return dp[a-1][b-1];
	}
}

//string subsequence 

int stringSubSequence(string s1,string s2){
	int n=s1.length();
	int m = s2.length();
	int dp[n+1][m+1];
	for(int i=0;i<m+1;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}

//maximum sum problem

int maxSumProblem(int n){
	int dp[n];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<n+1;i++){
		dp[i]=dp[i/2]+dp[i/3]+dp[i/4];
	}
	return dp[n];
}


//