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
// -----------------------------------------------------
pair<int,int>diameterOfBinaryTreeHelper(Node*root){
	if(!root)return make_pair(0,0);

	pair<int,int>left = diameterOfBinaryTreeHelper(root->left);
	pair<int,int>right = diameterOfBinaryTreeHelper(root->right);

	//this gives a value max path in either left subtree or right subtree
	int internal_path = max(left.second,right.second);

	//here when we add the root node if the that gives us the maximum then we update the internal path
	if(left.first+right.first+1>internal_path){
		internal_path=left.first+right.first+1;
	}
	return make_pair(max(left.first,right.first)+1,internal_path)
}
int diameterOfBinaryTree(Node*root){
	if(!root)return 0;
	pair<int,int>result = diameterOfBinaryTreeHelper(root);
	return max(result.first,result.second)-1;
}
//----------------------------------------------------------------
