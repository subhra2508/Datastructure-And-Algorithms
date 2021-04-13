//minimum number of partition required to make all the partition palindromic
//nitin so--n--iti--n

#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int i,int j){
     while(i<j){
        if(s[i]!=s[j]){
        	return false;
        }
        i++;
        j--;
     }
     return true;
}

int solve(string s,int i,int j){
    if(i>=j || isPalindrome(s,i,j)){return 0;}
    int ans=INT_MAX,count=0;
    for(int k=i;k<j;k++){
    	count=solve(s,i,k)+solve(s,k+1,j)+1;
    	ans=min(ans,count);
    }
    return ans;
}
int main(){
   string str="nitin";
   int i=0;
   int j=4;
   cout<<solve(str,i,j);
}