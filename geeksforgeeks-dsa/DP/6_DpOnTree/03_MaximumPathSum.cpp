//maximum path sum from any node to any node problem

#include<bits/stdc++.h>
using namespace std;

int solve(Node*root,int &res){
	if(root == nullptr)return 0;
	int l = solve(root->left,res);
	int r = solve(root->right,res);

	int temp = max(max(l+r)+root->val,root->val);
	int ans = max(temp,1+l+root->val);
	res = max(res,ans);

	return temp;
}
int main(){
	int res = INT_MIN;
	Node*root=NULL;
	solve(root,res);
	 
	return res;
}
