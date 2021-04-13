#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node*next;
};
Node*mergeSortedList(Node*lst1,Node*lst2){
	Node*result=NULL;
	if(lst1==NULL){
		return lst2;
	}
	if(lst2==NULL){
		return lst1;
	}
	if(lst1->data<=lst2->data){
		result=lst1;
		result->next=mergeSortedList(lst1->next,lst2);
	}
	else{
		result=lst2;
		result->next=mergeSortedList(lst1,lst2->next);
	}
	return result;
}
void splitList(Node*source,Node**front,Node**back){
	Node*ptr1;
	Node*ptr2;
	ptr2=source;
	ptr1=source->next;
	while(ptr1!=NULL){
		ptr1=ptr1->next;
		if(ptr1!=NULL){
			ptr2=ptr2->next;
			ptr1=ptr1->next;
		}
	}
	*front=source;
	*back=ptr2->next;
	ptr2->next=NULL;
}
void mergeSort(Node** thead){
	Node*head=*thead;
	Node*ptr1;
	Node*ptr2;
	if((head==NULL)||(head->next==NULL)){
		return;
	}
	splitList(head,&ptr1,&ptr2);
	MergeSort(&ptr1);
	MergeSort(&ptr2);
	*thead=mergesortedlist(ptr1,ptr2);

}
-------------------------------------------------------------------------------------------------------------------
//merge k sorted linked list
Node* mergetheLinkedList(Node * a,Node *b){ 
    Node*result=NULL;
    if(a==NULL)return b;
    else if(b==NULL)return a;
    if(a->data<=b->data){
        result=a;
        result->next=mergetheLinkedList(a->next,b);
    }
    else{
        result=b;
        result->next=mergetheLinkedList(a,b->next);
    }
    return result;
}
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       int i=1;
       while(i<N){
           arr[0]=mergetheLinkedList(arr[0],arr[i]);
           i++;
       }
       return arr[0];
}
--------------------------------------------------------------------------------------------------------------------
int main(){

}