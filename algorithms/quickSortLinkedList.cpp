struct Node*getTail(struct Node*curr){
	while(curr!=NULL&&curr->next!=NULL){
		curr=curr->next;
	}
	return curr;
}
struct Node*partition(struct Node*head,struct Node*end,struct Node**newHead,struct Node**newEnd){
	Node*pivot=end;
	Node*prev=NULL;
	Node*curr=head;
	Node*tail=pivot;

	while(curr!=pivot){//head!=end head=5,end=30,tail=30,pivot=30
		if(curr->data < pivot->data){
			if((*newHead)==NULL){
				(*newHead)=curr;//newHead=head //newHead=5;
			}
			prev=curr;//prev=5,prev=20 
			curr=curr->next;//curr=20,curr=40
		}
		else{//current data>the end data
			if(prev){
				prev->next=curr->next; //20->3 //curr=40
			}
			struct Node*temp=curr->next;//temp=3
			curr->next=NULL;//40->next=NULL
			tail->next=curr;//30->40
			tail=curr;//tail=40
			curr=temp;  //5->20->40->3->30  //curr=3
		}
	}
	if((*newHead)==NULL){
		(*newHead)==pivot;
	}
	(*newEnd)=tail;
	return pivot;
}
Node*quickSortRecur(Node*head,Node*end){
	if(!head||head==end)return head;
	Node*newHead=NULL;
	Node*newEnd=NULL;
	Node*pivot=partition(head,end,&newHead,&newEnd);
	if(newHead!=pivot){//newHead=5,newEnd=40
		Node*temp=newHead;
		while(temp->next!=pivot){//5->20->3->30->40
			temp=temp->next;
		}
		temp->next=NULL;//5->20->3->NULL
		newHead=quickSortRecur(newHead,temp);

		//change next of last node of the left half to pivot
		temp=getTail(newHead);//where we got the new tail
		temp->next=pivot;//than we joint the tail to the pivot
	}
	pivot->next=quickSortRecur(pivot->next,newEnd);
	return newHead;
}
void quickSort(Node**head_ref){
	(*head_ref)=quickSortRecur(*head_ref,getTail(*head_ref));
	return;
}