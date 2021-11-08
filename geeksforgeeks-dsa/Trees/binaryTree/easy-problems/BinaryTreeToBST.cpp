class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        set<int>s;
        extractKeys(root,s);
        auto it = s.begin();
        convertToBST(root,it);
        return root;
    }
    void extractKeys(Node*root,set<int>&s){
        if(!root)return;
        extractKeys(root->left,s);
        s.insert(root->data);
        extractKeys(root->right,s);
    }
    void convertToBST(Node*root,auto &it){
        if(!root)return;
        convertToBST(root->left,it);
        root->data = *it;
        it++;
        convertToBST(root->right,it);
    }
};