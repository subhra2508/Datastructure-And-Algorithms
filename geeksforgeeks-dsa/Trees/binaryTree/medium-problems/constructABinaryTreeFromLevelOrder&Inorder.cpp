Node*buildTree(int inorder[],int levelOrder[],int iStart,int iEnd,int n){
	if(n<=0)return nullptr;
	Node*root = levelOrder[0];


	int index = 0;
	for(int i=iStart;i<=iEnd;i++){
		if(inorder[i]==levelOrder[0]){
			index = i;
			break;
		}
	}


unordered_set<int>s;
for(int i=iStart;i<index;i++){
	s.insert(inorder[i]);
}

//separate level order Traversal of left and right subtree

int lLevel[s.size()];//left
int rLevel[iEnd-iStart-s.size()]//right

int li = 0;
int ri = 0;
for(int i=1;i<n;i++){
	if(s.find(levelOrder[i]) != s.end()){
		lLevel[li++] = levelOrder[i];
	}
	else{
		rLevel[ri++] = levelOrder[i];
	}
}

//Recursively build left and right
//subtrees and return root

root->left = buildTree(inorder,lLevel,iStart,index-1,index-iStart);
root->right = buildTree(inorder,rLevel,index+1,iEnd,iEnd-index);

return root;

}