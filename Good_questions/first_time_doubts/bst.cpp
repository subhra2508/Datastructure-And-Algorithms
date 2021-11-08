//binary search tree
#include<bits/stdc++.h>
using namespace std;
class BstNode{
	int data;
	BstNode(int data){

      this->data=data;
	BstNode*left=NULL;
	BstNode*right=NULL;}
};
BstNode *GetNewNode(int data){
	BstNode* newNode=new BstNode;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
void insert(BstNode**root,int data){
	BstNoded *temp=*root;
       if(*root==NULL){
       	*root=GetNewNode(data);
       }
       else if(data<=temp->data){
       	root->left=insert(temp->left,data);
       }
       else{
       	root->right=insert(temp->right,data);
       }
       return temp;
}
int main(){
BstNode *root;
root=NULL;
insert(root,15);
insert(root,10);
insert(root,20);
}

