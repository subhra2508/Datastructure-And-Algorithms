void mirror(Node*root){
	if(!root)return;
	else{
		Node*temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

bool isStructSame(Node*root1,Node*root2){
	if(root1==NULL && root2==NULL)return true;
	if(root1!=NULL && root2!=NULL && isStructSame(root1->left,root2->left) && isStructSame(root1->right,root2->right)){
		return true;
	}
	return false;
}

bool isFoldable(Node*root){
	bool res;
	if(root==NULL)return true;
	mirror(root->left);
	res = isStructSame(root->left,root->right);
	mirror(root->right);
	return res;
}
