Node *swapKthNode(Node*head,int num,int k){
	if(k>num)return head;
	if(2*k-1==num)return head;
	Node*x=head;
	Node*x_prev=NULL;
	for(int i=1;i<k;i++){
		x_prev=x;
		x=x->next;
	}
	Node*y=head;
	Node*y_prev=NULL;
	for(int i=1;i<n-k+1;i++){
		y_prev=y;
		y=y->next;
	}
	if(x_prev)x_prev->next=y;
	if(y_prev)y_prev->next=x;
	Node*temp=x->next;
	x->next=y->next;
	y->next=temp;
	return head;
}