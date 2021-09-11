void storeBST(Node*root,vector<Node*>&nodes){
    if(root==NULL)return ;
    storeBST(root->left,nodes);
    nodes.push_back(root);
    storeBST(root->right,nodes);
}

Node*buildBalancedTreeUtil(vector<Node*>&nodes,int start,int end){
    if(start > end) return NULL;
    int mid = (start+end)/2;
    Node*root = nodes[mid];
    root->left = buildBalancedTreeUtil(nodes,start,mid-1);
    root->right = buildBalancedTreeUtil(nodes,mid+1,end);
    return root;
}
// Your are required to complete this function
// function should return root of the modified BST
Node* buildBalancedTree(Node* root)
{
	// Code here
 vector<Node*>nodes;
 storeBST(root,nodes);
 int n = nodes.size();
 return buildBalancedTreeUtil(nodes,0,n-1);
}