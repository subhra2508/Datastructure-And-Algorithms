 int length(Node*head){
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
Node*reverse(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    Node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
 while(l1 && l1->data == 0)
        l1 = l1->next;
        // removing trailing zeroes from l1
    
    while(l2 && l2->data == 0)
        l2 = l2->next;
        // removing trailing zeroes from l2
    
    int n1 = length(l1);
    int n2 = length(l2);
    
    if(n2>n1)
        swap(l1,l2);
        // making sure l1 list has the bigger number
    
    if(n1==n2)
    {
        Node *t1=l1, *t2=l2;
        while(t1->data == t2->data )
        // finding which number is greater
        {
            t1 = t1->next;
            t2 = t2->next;
            
            if(!t1) return new Node(0);
            // returning zero if both numbers are same
        }
        if(t2->data > t1->data)
            swap(l1,l2);
            // making sure l1 list has the bigger number
    }
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    Node* res = NULL;
    Node* t1 = l1, *t2 = l2;
    while(t1)
    {
        int small = 0;
        if(t2) small = t2->data;
        // 'small' holds the next digit of number to be subtracted
        
        if( t1->data < small )
        {
            t1->next->data = t1->next->data - 1;
            t1->data = t1->data + 10;
            // taking carry
        }
        
        Node* n = new Node( t1->data - small );
        // creating new node for storing difference
        n->next = res;
        res = n;
        
        t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    
    while(res->next && res->data==0)
        res = res->next;
        // removing trailing zeroes from result list
    
    return res;