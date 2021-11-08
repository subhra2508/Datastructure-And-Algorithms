#include<bits/stdc++.h>
using namespace std;
class Node{
	int data;
	Node*next;
	Node*prev;
};

//insertion on a single linked list
void push(Node**head_ref,int new_datad){
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void insertionMiddle(Node*prev_node,int new_data){
	Node*new_node=new Node();
	if(prev_node==NULL)return;
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
void insertAtEnd(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	Node*temp=*head_ref;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
    while(temp->next!=NULL){
    	temp=temp->next;
    }
    temp->next=new_node;
    return;
}

//deletion in the single linkedlist
void deleteOnStart(Node**head_ref,int key){
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
	if(temp==NULL)return;
	prev->next=temp->next;
	delete temp;
}
void printList(Node*node){
	while(node!=NULL){
		cout<<node->data<<endl;
		node=node->next;
	}
}

//insertion in circular linked list
void push(Node**head_ref,int new_data){
	 Node*new_node=new Node();
	 new_node->data=new_data;
	 new_node->next=head_ref;
	 Node*temp=*head_ref;
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

void printCircularList(Node*head){
	Node*temp=head;
	if(temp!=NULL){
		do{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		while(temp!=NULL);
	}
}

//doubly linked list
//insertion
void push(Node**head_ref,int new_data){
	Node*new_node=new Node()
	new_node->data=new_data;
	new_node->next=*head_ref;
	new_node->prev=NULL;
	if(*(head_ref)!=NULL){
		*(head_ref)->prev=new_node; 
	}
	*head_ref=new_node;
}

void insertAtMiddle(Node*prev_node,int new_data){
    Node*new_node=new Node();
    new_node->data=new_data;
    new_node->next=prev_node->next;
    new_node->prev=prev_node;
    prev_node->next=new_node;
    if(new_node->next!=NULL){
    	new_node->next->prev=new_node;
    }

}
void insertAtEnd(Node**head_ref,int new_data){
	Node*new_node=new Node();
	new_node->data=new_data;
	new_node->next=NULL;
	Node*last=*head_ref;
	if(*head_ref==NULL){
	    new_node->prev=NULL;
	    *head_ref=new_node;
	    return ;
	}
	while(last->next!=NULL){
          last=last->next;
	}
	last->next=new_node;
	new_node->prev=last;
}

void deleteNode(Node**head_ref,Node*del){
	 if(*head_ref==NULL||del==NULL)return;
	 if(*head_ref==del){
	 	*head_ref=del->next;
	 }
	 if(del->next!=NULL){
	 	del->next->prev=del->prev;
	 }
	 if(del->prev!=NULl){
	 	del->prev->next=del->next;
	 }
	 free(del);
	 return;
}
//IF THE KEY OF THE DELETE NODE IS GIVEN

void findingThePosition(Node**head_ref,int n){
	if(*head_ref==NULL||n<=0)return;
	Node*current=*head_ref;
	for(int i=1;i<n&&current!=NULL;i++){
		current=current->next;
	}
	if(current==NULL)return;
	deleteNode(head_ref,current);
}

int main(){

}