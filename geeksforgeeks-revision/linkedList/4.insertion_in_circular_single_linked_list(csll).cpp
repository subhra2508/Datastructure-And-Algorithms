#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*next;
};
void push(Node**head_ref,int new_data){
	Node*new_node=new Node();
	Node*temp=*head_ref;
	new_node->data=new_data;
	new_node->next=*head_ref;
	if(temp!=NULL){
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
	}
	else{
		new_node->next=new_node;

	}
	*head_ref=new_node;
}
void printCircularLinkedList(Node*head){
	Node*temp=head;
	if(head!=NULL){
		do{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		while(temp!=head);
	}
}
int main(){
	Node*head=NULL;
	push(&head,23);
	push(&head,20);
	push(&head,18);
	printCircularLinkedList(head);
	return 0; 
}