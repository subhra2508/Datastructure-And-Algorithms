//important
//
class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(S==NULL)return true;
        if(T==NULL)return false;
        if(areIdentical(T,S)){
            return true;
        }
        return isSubTree(T->left,S) || isSubTree(T->right,S);
        
    }
    bool areIdentical(Node*T,Node*S){
        if(T==NULL && S==NULL)return true;
        if(T==NULL || S==NULL)return false;
        return (T->data == S->data && areIdentical(T->left,S->left) && 
        	areIdentical(T->right,S->right));
    }
};
//time complexity O(n^2);

// -----------------------------------------------------------------------------
// second approach
