void kthLargestUtil(Node*root,int k ,int c,int &ele){
	if(root==NULL || c>=k){
		return;
	}
	kthLargestUtil(root->right,k,c);
	c++;
	if(c==k){
		ele = root->data;
		return ;
	}
	kthLargestUtil(root->left,k,c,ele);

}



void kthLargest(Node*root,int k){
	int c = 0;
	int ele = -1;
	kthLargestUtil(root,k,c,ele);
	return ele;
}