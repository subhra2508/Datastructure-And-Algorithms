#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*next;
};
Node*insert(Node*head,int new_data){
Node*new_node=new Node();
new_node->data=new_data;
new_node->next=NULL;
if(head==NULL){
	head=new_node;
	return;
}
Node*last=head;
while(last->next!=NULL){
	last=last->next;
}
last->next=new_node;
return head;
}
Node*deleteNode(Node*head,int x){
	if(head==NULL)return nullptr;
	Node*temp=head;
	Node*prev;
	if(temp->data==x){
		head=temp->next;
		free(temp);
		return head;
	}
	while(temp!=NULL&&temp->data!=x){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)return head;
	prev->next=temp->next;
	free(temp);
	return head;
}
void printMail(Node*head){
	if(head==NULL){
		cout<<"EMPTY"<<endl;
	}
	else{
		Node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}
int main(){
 int t;
 cin>>t;
 while(t--){
 	int n,q;
 	cin>>n>>q;
 	 
 	Node*unread=NULL;
 	Node*read=NULL;
 	Node*trash=NULL;
 	for(int i=0;i<n;i++){
 		unread=insert(&unread,i);
 	}
 	for(int i=0;i<q;i++){
 		int r;
 		cin>>r;
 		int d;
 		cin>>d;
 		if(r==1){
 			unread=deleteNode(unread,d);
 			read=insert(read,d);
 		}
 		else if(r==2){
 			read=deleteNode(read,d);
 			trash=insert(trash,d);
 		}
 		else if(r==3){
 			unread=deleteNode(unread,d);
 			trash=insert(trash,d);
 		}
 		else if(r==4){
 			trash=deleteNode(trash,d);
 			read=insert(read,d);
 		}
 		else{
 			continue;
 		}
 	}
 }
}