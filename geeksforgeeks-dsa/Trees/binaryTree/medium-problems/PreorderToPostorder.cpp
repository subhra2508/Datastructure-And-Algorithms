// Construct BST from given preorder traversal using following algorithm:

// Create an empty stack.
// Make the first value as root. Push it to the stack.

// Keep on popping while the stack is not empty and the next value is greater than stack’s top value. 
//Make this value as the right child of the last popped node. Push the new node to the stack.

// If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node. 
//Push the new node to the stack.
// Repeat steps 3 and 4 until there are items remaining in pre[].
// The driver code will then use the root of this BST to print the postorder traversal.


// stack<Node*>stk;
// stk.push(root);

void findPostOrder(int pre[],int n){
	 stack<Node*>stk;
	 Node*root = newNode(pre[0]);
	 push(root);
	 int i;
	 Node*temp;
	 for(i=1;i<size;i++){
	 	temp=NULL;
	 	while(!stk.empty() && pre[i] > stk.top()){
	 		temp = stk.pop();
	 		if(temp!=NULL){
	 			temp->right = newNode(pre[i]);
	 			stk.push(temp->right);
	 		}
	 		else{
	 			Node*t = stk.top();
	 			t->left = newNode(pre[i]);
	 			stk.push(t->left);
	 		}
	 	}
	 }
	 return root;
 }

//not working
//authentication
//