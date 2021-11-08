Node*newNode(int data){
	Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int search(int arr[],int strt,int end,int value){
	for(int i=strt;i<=end;i++){
		if(arr[i]==value)return i;
		break;
	}
}
Node*buildUtil(int in[],int post[],int inStrt,int inEnd,int &pIndex){
	if(inStrt > inEnd)return NULL;
	Node*root = newNode(post[pIndex]);
	pIndex--;

	//if this node has no children then return the node
	if(inStrt==inEnd){
		return root;
	}
	int index = search(in,inStrt,inEnd,root->data);

	root->right = buildUtil(in,post,index+1,inEnd,pIndex);
	root->left = buildUtil(in,post,inStrt,index-1,pIndex);
	return root;
}

Node*buildTree(int in[],int post[],int n){
	int pIndex = n-1;
	return buildUtil(in,post,0,n-1,pIndex)
}