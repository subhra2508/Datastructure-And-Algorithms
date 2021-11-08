class Solution{
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code here
         vector<int>v;
         
         AncestorUtil(root,target,v);
         return v;
    }
    bool AncestorUtil(struct Node*root,int target,vector<int>&v){
        if(root==NULL)return false;
        
        if(root->data==target){
            return true;
        }
       
       if( AncestorUtil(root->left,target,v)||
        AncestorUtil(root->right,target,v)){
            v.push_back(root->data);
            return true;
        }
        return false;
    }
};