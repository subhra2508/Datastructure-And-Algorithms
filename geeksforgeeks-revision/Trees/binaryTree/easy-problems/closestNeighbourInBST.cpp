// Given a binary search tree and a number N, find the greatest number in the binary 
// search tree that is less than or equal to N. 
// Input : N = 24
// Output : 21
// Explanation : The greatest element in the tree which 
//               is less than or equal to 24, is 21. 
//               (Searching will be like 5->12->21)





int findMaxForN(Node*root,int N){
	if(!root)return -1;
	if(root->key < N){
		int k = findMaxForN(root->right , N);
		if(k==-1)return root->key;
	}
	else if(root->key > N){
		return findMaxForN(root->left,N);
	}
}