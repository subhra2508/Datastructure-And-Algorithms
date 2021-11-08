//case-1:the deleted node should be the left most node having no right child.
//case-2:the deleted node should be the right one having no left child.
//case-3:deleted node have both left and right child.
node* minValue(node*root){
	node*curr=root;
	while(curr&&curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
node* DeleteNode(node*root,int key){
       if(key<root->key){
          return DeleteNode(root->left,key);
       }else if(key>root->key){
       	return DeleteNode(root->right,key);
       }
       else{
       	if(root->left==NULL){
       		node*temp=root->right;
       		free(root);
       		return temp;
       	}if(root->left==NULL){
       		node*temp=root->left;
       		free(root);
       		return temp;
       	}
       	node *temp=minValue(root->right);
       	root->key=temp->key;
       	root->right=deleteNode(root->right,temp->key);
       }
       return root;
}