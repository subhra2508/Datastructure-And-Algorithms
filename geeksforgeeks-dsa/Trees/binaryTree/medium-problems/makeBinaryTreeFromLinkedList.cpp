void convertListToBinary(Node*head,TreeNode*&root){
	queue<TreeNode*>q;
	if(head == NULL){
		root = NULL;
		return;
	}

	//The first node is always the root node , and add it to the queue
	root = new TreeNode(head->data);
	q.push(root);
	head = head->next;

	while(head){
		TreeNode*parent = q.front();
		q.pop();

		TreeNode*leftChild = NULL;
		TreeNode*rightChild = NULL;
		leftChild = new TreeNode(head->data);
		q.push(leftChild);
		head = head->next;
		if(head){
			rightChild = new TreeNode(head->data);
			q.push(rightChild);
			head = head->next;
		}
		parent->left = leftChild;
		parent->right = rightChild;
	}
}