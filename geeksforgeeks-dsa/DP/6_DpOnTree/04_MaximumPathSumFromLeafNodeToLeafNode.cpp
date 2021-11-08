#include<bits/stdc++.h>
using namespace std;

int solve(Node*root,int &res){
	if(root == nullptr)return 0;
	int l = solve(root->left,res);
	int r = solve(root->right,res);

	int temp = max(l,r)+root->val;
	if(root->left==NULL&&root->right==NULL){
		temp = max(temp,root->val);
	}
	int ans = max(temp,l+r+root->val);
	res = max(res,ans);

	return temp;
}
int main(){
	int res = INT_MIN;
	Node*root=NULL;
	solve(root,res);
	return res;
}
