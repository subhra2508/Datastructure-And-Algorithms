void  storeNodes(Node*root,unordered_set<int>&all_nodes,unordered_set<int>&leaf_nodes){
	if(root==NULL)return;
	all_nodes.insert(root->data);
	if(root->left==NULL && root->right == NULL){
		leaf_nodes.insert(root->data);
	}
	storeNodes(root->left,all_nodes,leaf_nodes);
	storeNodes(root->right,all_nodes,leaf_nodes);
}

bool checkDeadEnd(Node*root){
	if(root==NULL)return false;
	unordered_set<int>all_nodes,leaf_nodes;
	storeNodes(root,all_nodes,leaf_nodes);
	for(auto i=leaf_nodes.begin();i!=leaf_nodes.end();i++){
		int x = (*i);
		if(all_nodes.find(x+1)!=all_nodes.end() && all_nodes.find(x-1)!=all_nodes.end()){
			return true;
		}
	}
	return false;
}