//using recurrsion
Node*delNodes(Node*head,int *maxval){
    if(head==NULL)return head;
    head->next=delNodes(head->next,maxval);
    if(head->data<(*maxval)){
        return head->next;
    }
    *maxval=max(head->data,*maxval);
    return head;
}
Node *compute(Node *head)
{
    // your code goes here
    int max=INT_MIN;
    head=delNodes(head,&max);
}