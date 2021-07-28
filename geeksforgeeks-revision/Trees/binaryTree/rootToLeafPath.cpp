void rootToLeafPathUtil(Node*root,vector<int>&v1,vector<vector<int>>&v){
	if(!root)return ;
	v1.push_back(root->data);
	if(root->left == NULL && root->right == NULL ){
		v.push_back(v1);
	}
	rootToLeafPathUtil(root->left,v1,v);
	rootToLeafPathUtil(root->right,v1,v);
	v1.pop_back();
}


vector<vector<int>>rootToLeafPath(Node*root){
	vector<vector<int>>v;
	vector<int>v1;
	rootToLeafPathUtil(root,v1,v);
	return v;
}