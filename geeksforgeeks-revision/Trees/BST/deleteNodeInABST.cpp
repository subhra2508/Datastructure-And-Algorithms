#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*left;
	Node*right;
};
Node*FindMin(Node*root){
	Node*temp = root;
	int minel = INT_MAX;
	Node*store=NULL;
	while(temp!=NULL){
        if(temp->data < minel){
        	minel = temp->data;
        	store = temp;
        }
        temp = temp->left;
	}
	return store;
}
Node*deleteNode(Node*root,int data){
	if(root==NULL)return nullptr;
	else if(data <root->data){
		root->left = deleteNode(root->left,data);
	}
	else if(data > root->data){
		root->right = deleteNode(root->right,data);
	}
	else{//wohoo... I found you , Get ready to be deleted

         //Case 1:No child
		if(root->left == NULL && root->right == NULL){
           delete root;
           root = NULL;
           return root;
		}
		//case 2: one child
		else if (root->left == NULL){
			Node*temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right == NULL){
			Node*temp = root->left;
			root = root->left;
			delete temp;
			return root;
		}
		else{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
			return root;
		}
	}
}
