
Node**firstPointer;
Node**secondPointer;


void pairwiseSwap(Node**root,int &count){
 if(!(*root))return ;
 if(!(*root)->left && !(*root)->right){
 	secondPointer=root;
 	count++;
 	if(count%2==0){
 		swap(firstPointer,secondPointer);
 	}
 	else{
 		firstPointer=secondPointer;
 	}
 }
 if(*(root)->left)pairwiseSwap(&(*root->left),count);
 if(*(root)->right)pairwiseSwap(&(*root->right),count);
}