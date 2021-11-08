class solution{
public:
	bool isHeap(Node*tree){
		int no_count = countNodes(tree);
		int index = 0;
		if(isCompleteUtil(tree,index,no_count)&&isHeapUtil(tree))return true;
		return false;
	}
	int countNodes(Node*root){
		if(!root)return 0;
		return 1+countNodes(root->left)+countNodes(root->right);
	}
	bool isCompleteUtil(Node*root,int index,int no_nodes){
		if(!root)return true;
		if(index >= no_nodes)return false;
		return (isCompleteUtil(root->left,index*2+1,no_nodes)&&isCompleteUtil(root->right,index*2+2,no_nodes));
	}
	bool isHeapUtil(Node*root){
		if(root->left==NULL&&root->right==NULL)return true;
		if(root->right==NULL){
			return (root->data >= root->left->data);
		}
		else{
			if(root->data >= root->left->data && root->data >= root->right->data){
				return isHeapUtil(root->left)&&isHeapUtil(root->right);
			}
			else
				return false;
		}
	}
}