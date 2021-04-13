Node* merge(Node*first,Node*second){
	if(!first){
		return second;
	}
	if(!second){
		return first;
	}
	if(first->data<second){
		first->next=mergeSort(first->next,second);
		first->next->prev=first;
		first->prev=NULL;
		return first;
	}
	else{
		second->next=merge(first,second->next);
		second->next->prev=second;
		second->prev=NULL;
		return second;
	}
}
Node*splitList(Node*head){
	Node*fast_ptr=head;
	Node*slow_ptr=head;
	while(fast_ptr&&slow_ptr&&fast_ptr->next){
		fast_ptr=fast_ptr->next->next;
		slow_ptr=slow_ptr->next;
	}
	Node*temp=slow_ptr->next;
	slow_ptr->next=NULL;
	return temp;
}
Node*mergeSort(Node*head){
	if(head==NULL&&head->next==NULL)return head;
	Node*second=splitList(head);
	head=mergeSort(head);
	second=mergeSort(second);
	return merge(head,second);
}