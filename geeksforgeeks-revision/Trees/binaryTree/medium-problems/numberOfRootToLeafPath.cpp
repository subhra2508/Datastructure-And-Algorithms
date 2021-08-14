void inorderTraversal(Node*root,vector<int>&v,stack<int>&stk){
	if(root==NULL)return ;
	stk.push(root->data);
	inorderTraversal(root->left,v,stk);
	if(root->left == NULL && root->right == NULL){
		v.push_back(stk.size());
	}
	inorderTraversal(root->right,v,stk);
	stk.pop();
}