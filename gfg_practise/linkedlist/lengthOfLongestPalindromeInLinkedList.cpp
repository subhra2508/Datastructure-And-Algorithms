int countCommon(Node*a,Node*b){
	int count=0;
	for(;a&&b;a=a->next,b=b->next){
		if(a->data==b->data){
			count++;
		}
		else{
			break;
		}
	}
	return count;
}
int maxPalindrome(Node*head){
	int result=0;
	Node*prev=NULL;
	Node*curr=head;
	while(curr){
		Node*next=curr->next;
		curr->next=prev;
		result=max(result,2*countCommon(prev,next)+1);
		result=max(result,2*countCommon(curr,next));
		prev=curr;
		curr=next;
	}
	return result;
}