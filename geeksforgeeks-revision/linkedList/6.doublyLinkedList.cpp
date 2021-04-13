#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*next;
	Node*prev;
};
void push(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	new_node->prev=NULL;
	if(*(head_ref)!=NULL){
		(*head_ref)->prev=new_node;
	}
	*head_ref=new_node;
}
void insertAfter(Node*prev_node,int new_data){
	if(prev_node==NULL)return ;
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=prev_node->next;
	new_node->prev=prev_node;
	prev_node->next=new_node;
	if(new_node->next!=NULL){
		new_node->next->prev=new_node;
	}
}
void insertEnd(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	Node*temp=*head_ref;
	new_node->next=NULL;
	if(*head_ref==NULL){
		new_node->prev=NULL;
		*head_ref=new_node;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
}
void printList(Node*node){
	Node*last;
	printf("printting the list in forward direction ");
	while(node!=NULL){
		cout<<node->data<<" ";
		last=node;
		node=node->next;
	}
	cout<<endl;

	printf("printing the list in backward direction ");
	cout<<endl;
	while(last!=NULL){
		cout<<last->data<<" ";
		last=last->prev;
	}
}
void insertBefore(Node**head_ref,Node*next_node,int new_data){
	if(next_node==NULL){
		return;
	}
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->prev=next_node->prev;
	next_node->prev=new_node;
	new_node->next=next_node;
	if(new_node->prev!=NULL){
		new_node->prev->next=new_node;
	}
	(*head_ref)=new_node;

}
int main(){
  Node*head=NULL;
  push(&head,12);
  push(&head,20);
  push(&head,30);
  insertBefore(&head,head->next,9);
  printList(head);
  return 0;
}