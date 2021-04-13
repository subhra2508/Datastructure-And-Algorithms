void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    if(head==NULL||head->next==NULL)return;
    Node*fast_ptr=head;
    Node*slow_ptr=head;
    slow_ptr=slow_ptr->next;
    fast_ptr=fast_ptr->next->next;
    
    while(fast_ptr&&fast_ptr->next){
        if(slow_ptr==fast_ptr)break; 
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
       
    }
    if(slow_ptr==fast_ptr){
        slow_ptr=head;
        if(slow_ptr==fast_ptr){
            while(fast_ptr->next!=slow_ptr){//just imagine the case we have two nodes
            fast_ptr=fast_ptr->next;
            }
        }
        else{
            while(slow_ptr->next!=fast_ptr->next){
                slow_ptr=slow_ptr->next;
                fast_ptr=fast_ptr->next;
            }
        }
        fast_ptr->next=NULL;
    }
}