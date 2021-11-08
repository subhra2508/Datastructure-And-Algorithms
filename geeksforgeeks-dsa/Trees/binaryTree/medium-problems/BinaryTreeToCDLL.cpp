Node*concatenate(Node*leftList,Node*rightList){

	if(leftList == NULL)return rightList;
	if(rightList == NULL)return leftList;

	// Store the last Node of left List
    Node *leftLast = leftList->left;

	// Store the last Node of right List
    Node *rightLast = rightList->left;


    // Connect the last node of Left List
    // with the first Node of the right List
	leftLast->right =rightList;
	rightList->left = leftLast;

	// Left of first node points to
    // the last node in the list
    leftList->left = rightLast;


	// Right of last node refers to the first
    // node of the List
    rightLast->right = leftList;

	return leftList;
}

Node*bTreeToCList(Node*root){
	if(root==NULL) return NULL;
	Node*left = bTreeToCList(root->left);
	Node*right = bTreeToCList(root->right);
	//here we are making an circular linkedlist
	root->left = root->right = root;
	return concatenate(concatenate(left,root),right);
}