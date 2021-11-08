void kDistantFromLeafUtil(Node*root,int path[],bool visited[],int pathLen,int k,vector<int>&v){
    if(!root)return;
    path[pathLen]=root->data;
    visited[pathLen]=false;
    pathLen++;
    if(root->left == NULL && root->right == NULL &&
    pathLen-k-1 >=0 && visited[pathLen-k-1]==false){
        v.push_back(path[pathLen-k-1]);
        visited[pathLen-k-1]=true;
    }
    kDistantFromLeafUtil(root->left,path,visited,pathLen,k,v);
    kDistantFromLeafUtil(root->right,path,visited,pathLen,k,v);
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here. 
	
	int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT]={false};
	vector<int>v;
	kDistantFromLeafUtil(root,path,visited,0,k,v);
	return v.size();
}