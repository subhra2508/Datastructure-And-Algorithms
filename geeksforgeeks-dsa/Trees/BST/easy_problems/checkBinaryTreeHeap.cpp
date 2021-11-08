class Solution {
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int nodes_count = count(tree);
        int index = 0;
        if(isCompleteTree(tree,index,nodes_count)&&isHeapUtil(tree)){
            return true;
        }
        return false;
    }
    int count(Node*root){
        if(root==NULL)return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool isCompleteTree(Node*root,int index,int nodes_count){
        if(root==NULL)return true;
        if(index > nodes_count)return false;
        return(isCompleteTree(root->left,2*index+1,nodes_count)&&
        isCompleteTree(root->right,2*index+2,nodes_count));
    }
    bool isHeapUtil(Node*root){
        if(root->left == NULL && root->right == NULL )return true;
        if(root->right == NULL){
            return (root->data >= root->left->data);
        }
        else{
            if(root->data >= root->left->data && root->data >= root->right->data){
                return isHeapUtil(root->left)&&isHeapUtil(root->right);
            }
            else
            return false;
        }
    }
};