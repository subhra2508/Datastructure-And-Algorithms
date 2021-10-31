/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)return head;
        flatten_list(head);
        return head;
    }
    Node* flatten_list(Node*ptr){
        
        if(ptr->next == NULL && ptr->child == NULL){
            return ptr;
        }
        if(ptr->child!=nullptr){
            Node*pt = flatten_list(ptr->child);
            
            if(ptr->next){
                Node*nxt= ptr->next;
                nxt->prev = pt;
                pt->next = nxt;
                ptr->next = ptr->child;
                (ptr->child)->prev = ptr;
                ptr->child = nullptr;
                
            }
            else{
                ptr->next = ptr->child;
                (ptr->child)->prev = ptr;
                ptr->child = nullptr;
                flatten_list(ptr);
            }
        }
        return flatten_list(ptr->next);
    }
};