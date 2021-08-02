int LISS(Node*root){
	if(root==NULL)return 0;
	int excl = LISS(root->left)+LISS(root->right);
	int incl = 1;
	if(root->left) incl+=LISS(root->left->left)+LISS(root->left->right);
	if(root->right)incl +=LISS(root->right->left)+LISS(root->right->right);
	return max(excl,incl);
}