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

	// If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
	else if(data <root->data){
		root->left = deleteNode(root->left,data);
	}

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
	else if(data > root->data){
		root->right = deleteNode(root->right,data);
	}

	// if key is same as root's key, then This is the node
    // to be deleted(root->data == data ) this is the else case
	else{//wohoo... I found you , Get ready to be deleted

         //Case 1:No child
		if(root->left == NULL && root->right == NULL){
           delete root;
           root = NULL;
           return root;
		}
		//case 2: one child
		else if (root->left == NULL){
			struct node* temp = root->right;
            free(root);
            return temp;
		}
		else if(root->right == NULL){
			struct node* temp = root->left;
            free(root);
            return temp;
		}
		 // when we have both childs
        Node*temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletionBT(root->right,temp->data);
    }
    return root;
}
