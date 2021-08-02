// delete the deepest node and replace the data with the known node

void deleteDeepest(Node*root,Node*d_node){
	queue<Node*>q;
	q.push(root);
	Node*temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp==d_node){
			temp = NULL;
			delete(d_node);
			return ;
		}
		if(temp->left){
			if(temp->left == d_node){
				temp->left=NULL;
				delete(d_node);
				return ;
			}
			else{
				q.push(temp->left);
			}
		}
		if(temp->right){
			if(temp->right == d_node){
				temp->right = NULL;
				delete(d_node);
				return ;
			}
			else{
				q.push(temp->right);
			}
		}
	}
}



//function to delete node in a binary tree
Node*deleteNode(Node*root,int key){
	if(root==NULL)return NULL;
	if(root->left == NULL && root->right == NULL){
		if(root->data == key){
			delete(root);
			return NULL;
		}
		else{
			return root;
		}
	}
	queue<Node*>q;
	q.push(root);
	Node*temp;
	Node*key_node = NULL;

	//do level order traversal to find deepest
	//node(temp) and node to be deleted(key_node)

	while(!q.empty()){
		temp=q.front();
		q.pop();

		//here we can find the node to be deleted
		if(temp->key == key){
			key_node = temp;
		}
		if(temp->left){	 
		q.push(temp->left);		 
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
		if(key_node!=NULL){
			int x = temp->key;
			deleteDeepest(root,temp);
			key_node->key = x;
		}
		return root;
}