#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*left;
	Node*right;
	Node(){data=0,left=NULL,right=NULL}{}
	Node(int val){data=val,left=NULL,right = NULL}{}
}
void kthLargestUtil(Node*root,int k,int &c,int &ans){
	if(!root || c>=k)return ;
	kthLargestUtil(root->right,k,c,ans);
	c++;
	if(c==k){
		ans = root->data;
		return ;
	}
	kthLargestUtil(root->left,k,c,ans);
}
int kthLargest(Node*root,int k){
	int c = 0;
	int ans = 0;
	kthLargestUtil(root,c,k,ans);
	return ans;
}
int main(){

}