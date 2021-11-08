//Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.


Node*copyLeftRightNode(Node*tree,unordered_map<Node*,Node*>&mp){
	if(tree == NULL)return NULL;
	Node*cloneNode = new Node(tree->data);
	mp[tree] = cloneNode;
	cloneNode->left = copyLeftRightNode(tree->left,mp);
	cloneNode->right = copyLeftRightNode(tree->right,mp);
	return cloneNode;
}

void copyRandom(Node*tree,Node*cloneNode,unordered_map<Node*,Node*>&mp){
	if(cloneNode == NULL)return ;
	cloneNode->random = mp[tree->random];
	copyRandom(tree->left,cloneNode->left,mp);
	copyRandom(tree->right,cloneNode->right,mp);
}

Node*cloneTree(Node*tree){
	if(tree == NULL)return NULL;
	unordered_map<Node*,Node*>mp;
	Node*newTree = copyLeftRightNode(tree,mp);
	copyRandom(tree,newTree,mp);
	return newTree;
}
