class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node*lca = LCA(root,a,b);
        int d1 = findLevel(lca,a,0);
        int d2 = findLevel(lca,b,0);
        return d1+d2;
    }
    Node*LCA(Node*root,int n1,int n2){
        if(root==NULL)return root;
        if(root->data == n1 || root->data == n2)return root;
        Node*left = LCA(root->left,n1,n2);
        Node*right = LCA(root->right,n1,n2);
        if(left && right )return root;
        return left?left:right;
    }
    int findLevel(Node*root,int k,int level){
        if(root==NULL)return -1;
        if(root->data == k)return level;
        int left = findLevel(root->left,k,level+1);
        if(left == -1){
            return findLevel(root->right,k,level+1);
        }
        return left;
    }
    
};