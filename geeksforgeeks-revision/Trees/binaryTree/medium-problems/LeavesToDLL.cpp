#include<bits/stdc++.h>
using namespace std;

Node*extractLeafList(Node*root,Node*head_ref){
	if(root==NULL)return NULL;
	if(root->left == NULL && root->right == NULL){
		root->right = *head_ref;
		if((*head_ref)!=NULL)(*head_ref)->left = root;
		*head_ref=root;
		return NULL;
	}
	root->right = extractLeafList(root->right,head_ref);
	root->left = extractLeafList(root->left,head_ref);
	return root;
}


Node * convertToDLL(Node *root){
    // add code here.
    Node*head = NULL;
   root = extractLeafList(root,&head);
   return head;
}
