//sum of left leaves nodes
int leftLeavesSum(Node *root)
{
    // Code here
     if(root==NULL)return 0;
     if(root->left!=NULL&&(root->left->right==NULL&&root->left->left==NULL))
     return root->left->data+leftLeavesSum(root->right);
     else
     return leftLeavesSum(root->left)+leftLeavesSum(root->right);
    
}
//sum of right leaves
int rightLeafSum(Node* root)
{
     //Code here
       if(root==NULL)return 0;
       if(root->right!=NULL&&(root->right->left==NULL&&root->right->right==NULL))
       return root->right->data+rightLeafSum(root->left);
       else
       return rightLeafSum(root->left)+rightLeafSum(root->right);
}
//another sum of right leaves
void find(Node*root,int *sum){
    if(root==NULL)return ;
    if(root->right){
        if(root->right->left==NULL&&root->right->right==NULL){
            *sum+=root->right->data;
        }
       
    } find(root->left,sum);
        find(root->right,sum);
    
}
int rightLeafSum(Node* root)
{
     //Code here
       int sum=0;
       find(root,&sum);
       return sum;
}
