Node* LCA(Node*root,int n1,int n2){
	if(!root)return NULL;
	if(root->data == p || root->data == q){
		return root;
	}
	Node*left = LCA(root->left,n1,n2);
	Node*right = LCA(root->right,n1,n2);
	if(left != NULL && right !=NULL){
		return root;
	}
	return left?left:right;
}