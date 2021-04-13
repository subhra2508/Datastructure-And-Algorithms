 Node*addsameSize(Node*head1,Node*head2,int*carry){
 	if(head1==NULL){
 		return NULL;
 	}
 	int sum;
 	Node*result=(struct Node*)malloc(sizeof(struct Node));
 	result->next=addsameSize(head1->next,head2->next,int*carry);
 	sum=head1->data+head2->data+*carry;
    *carry=sum/10;
    sum=sum%10;
    result->data=sum;
    return result;
 }
 void addCarryToRemaining(Node*head1,Node*curr,int*carry,Node**result){
 	int sum;
 	if(head1!=cur){
 		addCarryToRemaining(head1->next,cur,carry,result);
 		sum=head1->data+*carry;
 		*carry=sum/10;
 		sum=sum%10;
 		push(result,sum);
 	}
 }
 void addList(Node* head1, Node* head2, Node** result)
{
    Node* cur;
 
    // first list is empty
    if (head1 == NULL) {
        *result = head2;
        return;
    }
 
    // second list is empty
    else if (head2 == NULL) {
        *result = head1;
        return;
    }
 
    int size1 = getSize(head1);
    int size2 = getSize(head2);
 
    int carry = 0;
 
    // Add same size lists
    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
 
    else {
        int diff = abs(size1 - size2);
 
        // First list should always be larger than second
        // list. If not, swap pointers
        if (size1 < size2)
            swapPointer(&head1, &head2);
 
        // move diff. number of nodes in first list
        for (cur = head1; diff--; cur = cur->next)
            ;
 
        // get addition of same size lists
        *result = addSameSize(cur, head2, &carry);
 
        // get addition of remaining first list and carry
        addCarryToRemaining(head1, cur, &carry, result);
    }
 
    // if some carry is still there, add a new node to the
    // fron of the result list. e.g. 999 and 87
    if (carry)
        push(result, carry);
}