Node*removeHalfNodes(Node*root){
	if(!root)return nullptr;
	root->left = removeHalfNodes(root->left);
	root->right = removeHalfNodes(root->right);
	if(root->left == NULL && root->right == NULL)return root;
	if(!root->left){
		Node*new_root = root->right;
		free(root);
		return new_root;
	}
	if(!root->right){
		Node*new_root = root->left;
		free(root);
		return new_root;
	}
	return root;
}