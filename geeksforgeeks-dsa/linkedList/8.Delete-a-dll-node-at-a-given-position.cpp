#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*prev;
	Node*next;
};
void push(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	new_node->prev=NULL;
	if(*head_ref!=NULL){
		(*head_ref)->prev=new_node;
	}
	*head_ref=new_node;
}
void deleteNode(Node**head_ref,Node*del){
	if(*head_ref==NULL||del==NULL)return;
	if(del==*head_ref){
		*head_ref=del->next;
	}
	if(del->next!=NULL){
		del->next->prev=del->prev;
	}
	if(del->prev!=NULL){
		del->prev->next=del->next;
	}
	free(del);
	return;
}
void findingDeletePosition(Node**head_ref,int n){
	if(*head_ref==NULL||n<=0){
		return;
	}
	Node*current=*head_ref;
	for(int i=1;current!=NULL&&i<n;i++){
		current=current->next;
	}
	if(current==NULL)return;
	deleteNode(head_ref,current);
}
void printList(Node*node){
	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
}
int main(){
    Node*head=NULL;
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    printList(head);cout<<endl;
    findingDeletePosition(&head,2);
    printList(head);cout<<endl;
    findingDeletePosition(&head,1);
    printList(head);cout<<endl;
}