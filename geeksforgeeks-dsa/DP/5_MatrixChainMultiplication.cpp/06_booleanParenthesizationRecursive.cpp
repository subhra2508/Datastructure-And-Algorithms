//This problem is also known as the Evaluate Expression To True

//the string must be constructed in --> & || ^ T F

//Number of ways inorder to make the string T

//string s="T|F&T^F";

//#No of true case = T^F + F^T

#include<bits/stdc++.h>
using namespace std;
int solve(string str,int i,int j ,bool isTrue){
     if(i>j)return false;
     if(i==j){
     	if(isTrue==True) return s[i]=='T';
     	else
     		return s[i]=='F';
     }
     int ans = 0;
     for(int k=i+1;k<=j-1;k=k+2){
     	int lt = solve(s,i,k-1,'T');
     	int lf = solve(s,i,k-1,'F');
     	int rt = solve(s,k+1,j,'T');
     	int rf = solve(s,k+1,j,'F');
     
     if(s[k] == '&'){
     	if(isTrue == 'T'){
     		ans = ans + lt*rt;
     	}
     	else{
     		ans = ans+lf*rt+lf*rf+lt*rf;
     	}
     }
     elseif(s[k]=='|'){
     	if(isTrue=='T') ans = ans+lt*rt+lt*rf+lf*rt;
     	else ans = ans+lf*lf;
     }
     elseif(s[k]=='^'){
     	if(isTrue=='T'){
     	   ans = ans+lf*rt+lt*rf;	
     	}
     	else{
     		ans = ans+lt*rt+lf*rf;
     	}

     }
 }
 return ans;
}

int main(){
 
}


 // if (dp[i][k - 1][1] == -1)
 //        {
 //            leftT = parenthesis_count(s, i, k - 1, 1);
 //        } // Count no. of T in left partition
 //        else {
 //            leftT = dp[i][k - 1][1];
 //        }
 
 //        if (dp[k + 1][j][1] == -1)
 //        {
 //            rightT = parenthesis_count(s, k + 1, j, 1);
 //        } // Count no. of T in right partition
 //        else
 //        {
 //            rightT = dp[k + 1][j][1];
 //        }
 
 //        if (dp[i][k - 1][0] == -1)
 //        {
 //            // Count no. of F in left partition
 //            leftF = parenthesis_count(s, i, k - 1, 0);
 //        }
 //        else
 //        {
 //            leftF = dp[i][k - 1][0];
 //        }
 
 //        if (dp[k + 1][j][0] == -1)
 //        {
 //            // Count no. of F in right partition
 //            rightF = parenthesis_count(s, k + 1, j, 0);
 //        }
 //        else
 //        {
 //            rightF = dp[k + 1][j][0];
 //        }

