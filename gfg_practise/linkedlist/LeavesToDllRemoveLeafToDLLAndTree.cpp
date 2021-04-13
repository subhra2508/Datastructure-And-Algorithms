Node*extractLeaves(Node*root,Node**head_ref){
	if(root==NULL)return NULL;
	if(root->left==NULL&&root->right==NULL){
		root->right=*head_ref;
		if(*head_ref!=NULL){
			(*head_ref)->left=root; 
		}
		(*head_ref)=root;
		return NULL;
	}
	root->right=extractLeaves(root->right,head_ref);
	root->left=extractLeaves(root->left,head_ref);
	return root;
}


Node*convertToDLL(Node*root){
	Node*head_ref=NULL;
	root=extractLeaves(root,&head_ref)
	return head_ref;//returning the head of the doubly linkedlist
}
