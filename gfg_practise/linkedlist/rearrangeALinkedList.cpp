 
Node *rearrangeEvenOdd(Node *head)
{
   // Your Code here
   if(head==NULL)return NULL;
   Node*odd=head;
   Node*even=head->next;
   Node*evenFirst=even;
   while(1){
   if(!odd||!even||!(even->next))//boundary conditions
   {
       odd->next=evenFirst;
       break;
   }
   odd->next=even->next;
   odd=even->next;
   if(odd->next==NULL){
       even->next=NULL;
       odd->next=evenFirst;
       break;
   }
   even->next=odd->next;
   even=odd->next;
       
   }
   return head;
}