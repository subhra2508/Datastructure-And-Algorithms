// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}
// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node*reverse(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    Node*next_ptr=NULL;
    while(curr){
        next_ptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_ptr;
    }
    return prev;
}
void splitlist(Node*head,Node**head1,Node**head2){
    (*head1)=head;
    (*head2)=head->next;
    Node*temp;
    Node*ptr;
    temp=head;
    ptr=head->next;
    while(ptr){
        temp->next=ptr->next;
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    
}
Node*merge(Node*head1,Node*head2){
       if(!head1&&!head2)return NULL;
       if(!head1){
           return head2;
       }
       if(!head2){
           return head1;
       }
       Node*final;
       if(head1->data<head2->data){
           final=head1;
           final->next=merge(head1->next,head2);
       }else{
           final=head2;
           final->next=merge(head1,head2->next);
       }
       return final;
}
void sort(Node **head)
{
     // Code here
      if(!(*head)){
          return;
      }
      Node*head1,*head2;
      splitlist(*head,&head1,&head2);
      head2=reverse(head2);
      (*head)=merge(head1,head2);
 

