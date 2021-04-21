//diameter of a binary tree
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* left,*right;
};

//DEMO CODE (NOT THE RIGHT ONE)

int solve(Node*root,int &res){
	if(root == nullptr)return 0;
	int l = solve(root->left,res);
	int r = solve(root->right,res);

	int temp =
	int ans = max(temp,1+l+r);
	res = max(res,ans);

	return temp;
}

int main(){
	int res = INT_MIN;
	Node*root=NULL;
	solve(root,res);
	[](){cout<<"subhrajyoti sankar sau.";};
	return res;
}