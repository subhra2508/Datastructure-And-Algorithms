#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countWays(string S1, string S2){
        // code here
        int m=S1.length();
        int n=S2.length();
        int lookup[m+1][n+1]={{0}};
        for(int i=0;i<=n;i++){
            lookup[0][i]=0;
        }
        for(int i=0;i<=m;i++){
            lookup[i][0]=1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(S1[i-1]==S2[j-1]){
                    lookup[i][j]=lookup[i-1][j-1]+lookup[i-1][j];
                }
                else{
                    lookup[i][j]=lookup[i-1][j];
                }
            }
        }
        return lookup[m][n];
    }
};
int main(){
	 
}