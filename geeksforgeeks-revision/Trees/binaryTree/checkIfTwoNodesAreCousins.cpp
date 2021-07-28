

// If two nodes are cousins then
// 1.they have to be in the same level 
// 2.they don't siblings of each other


int isSiblings(Node*root,int a,int b){
	if(!root)return 0;
	return ((root->left->data == a && root->right->data = b )||
		(root->left->data == b && root->right->data == a)||
		(isSiblings(root->left,a,b))||
		(isSiblings(root->right,a,b))
		);

}
//recursive function to find the level of a node in Binary tree
int level(Node*root,int data,int lev){
	if(root == NULL)return 0;
	if(root->data == data)return lev;
	int l = level(root->left,data,lev+1);
	if(l!=0)return l;
	return level(root->right,data,lev+1);
}

int isCousin(Node*root,int a,int b){
	if(!root)return 0;
	if(!isSiblings(root,a,b)&&level(root,a,1)==level(root,b,1))return 1;
	else
		return 0;
}