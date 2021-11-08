#include<bits/stdc++.h>
using namespace std;
void LCA(Node*root,Node* n1,Node* n2){
	if(root==NULL)return NULL;
	if(root==n1||root==n2)
		return root;
	left=LCA(root->left,n1,n2);
	right=LCA(root->right,n1,n2);
	if(left!=NULL&&right!=NULL)return root;
	else
		return (left?left:right)

}
int main(){

}