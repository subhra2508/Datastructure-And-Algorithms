Node* mergetheLinkedList(Node * a,Node *b){ 
    Node*result=NULL;
    if(a==NULL)return b;
    else if(b==NULL)return a;
    if(a->data<=b->data){
        result=a;
        result->next=mergetheLinkedList(a->next,b);
    }
    else{
        result=b;
        result->next=mergetheLinkedList(a,b->next);
    }
    return result;
}
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       int i=1;
       while(i<N){
           arr[0]=mergetheLinkedList(arr[0],arr[i]);
           i++;
       }
       return arr[0];
}