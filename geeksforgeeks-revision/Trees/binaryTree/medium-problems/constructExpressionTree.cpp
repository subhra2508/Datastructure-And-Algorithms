bool isOperator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')return true;
	return false;
}

Node*expressionTree(char postfix[]){
	stack<Node*>stk;
	Node*t,*t1,*t2;
	for(int i=0;i<strlen(postfix);i++){
		if(!isOperator(postfix[i])){
			t = new Node(postfix[i]);
			stk.push(t);
		}
		else{
			t = new Node(postfix[i]);
			t1= stk.top();
			stk.pop();
			t2= stk.top();
			stk.pop();
			t->right = t1;
			t->left = t2;
		}
	}
	t = stk.top();
	stk.pop();
	return t;
}