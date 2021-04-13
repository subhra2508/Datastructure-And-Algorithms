Node*copyList(Node*head){
	Node*curr=head;
	Node*temp;
	while(curr){
		temp=curr->next->next;
		curr->next=new Node(curr->data);
		curr->next=temp;
	}
	curr=head;
	while(curr){
		if(curr->next){
			curr->next->arb=curr->arb?curr->arb->next:curr->arb;
			curr=curr->next?curr->next->next:curr->next;
		}
	}
	Node*original=head;
	Node*copy=head->next;
	temp=copy;
	while(original&&copy){
		original->next=original->next?original->next->next:original->next;
		copy->next=copy->next?copy->next->next:copy->next;
		original=original->next;
		copy=copy->next;
	}
	return temp;
}
// Node *copyList(Node *head) {
//     // Your code here
//     Node*curr=head;
//     Node*temp;
//     //insert additional node after every node of original list
//     while(curr){
//         temp=curr->next;
//         //inserting node
//         curr->next=new Node(curr->data);
//         curr->next->next=temp;
//         curr=temp;
//     }
//     curr=head;
//     //adjust the random pointers of the newly added nodes
//     while(curr){
//         if(curr->next){
//             curr->next->arb=curr->arb?curr->arb->next:curr->arb;
//             //move to the next newly added node by skipping an original node
//             curr=curr->next?curr->next->next:curr->next;
//         }
//     }
//     Node*original=head;
//     Node*copy=head->next;
//     //save the start of copied List
//     temp=copy;
//     while(original&&copy){
//         original->next=original->next?original->next->next:original->next;
//         copy->next=copy->next?copy->next->next:copy->next;
//         original=original->next;
//         copy=copy->next;
//     }
//     return temp;
// }