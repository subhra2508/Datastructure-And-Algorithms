//revision required
Node*concatenate(Node*leftList,Node*rightList){
	if(leftList==NULL)return rightList;
	if(rightList==NULL)return leftList;
     
     //store the last Node of left list
	Node*leftLast=leftList->left;
	//store the last Node of the right list
	Node*rightLast=rightList->left;
     
     //connect the last node of left list
	//with the first Node of the right list
	leftLast->right=rightList;
	rightList->left=leftLast;
     
     //left of first node points to the last node in the list
	leftList->left=rightLast;
	//right of last node refers to the first node of the list
	rightLast->right=leftList;

	retur leftList;

}
Node*bTreeToCList(Node*root){
	if(root==NULL)return NULL;
	Node*left=bTreeToCList(root->left);
	Node*right=bTreeToCList(root->right);
	root->left=root->right=root;
	return concatenate(concatenate(left,root),right);
}