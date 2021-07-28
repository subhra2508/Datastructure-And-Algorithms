int findMaxForN(Node*root,int N){
	if(!root)return -1;
	if(root->key == N)return N;
	if(root->key < N){
		int k = findMaxForN(root->left,N);
		if(k==-1)return root->key;
		return k;
	}
	else if(root->key > N){
		return findMaxForN(root->right,N);
	}
}