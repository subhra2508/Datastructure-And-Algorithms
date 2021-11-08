#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
void push(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void deleteNode(Node**head_ref,int key){
	Node*temp=*head_ref;
	Node*prev;
	if(temp!=NULL&&temp->data==key){
		*head_ref=temp->next;
		delete temp;
		return;
	}
	while(temp!=NULL&&temp->data!=key){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		return;
	}
	prev->next=temp->next;
	delete temp;
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
  push(&head,18);
  push(&head,20);
  push(&head,30);
  push(&head,40);
  printList(head);
  deleteNode(&head,20);
  printList(head);
}