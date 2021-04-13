#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*next;
};
//inserting the node at the front of the linkedlist
void push(Node**head_ref,int new_data){
    Node *new_node=new Node();//struct(Node*)malloc(sizeof(new_node))	
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
//inserting the node at the middle of the linkedlist
void insertMiddle(Node*prev_node,int new_data){
	Node*new_node=new Node();
	if(prev_node==NULL)return;
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
//inserting the node at the end of the linkedlist
void insertLast(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	Node*last=*head_ref;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	return;
}
void printList(Node*head_ref){
	while(head_ref!=NULL){
		cout<<head_ref->data<<" ";
		head_ref=head_ref->next;
	}
	cout<<endl;
}
int main(){
    Node*head=NULL;
    insertLast(&head,6);
    push(&head,10);
    push(&head,16);
    push(&head,20);
    insertMiddle(head->next->next,31);
    printList(head);
}