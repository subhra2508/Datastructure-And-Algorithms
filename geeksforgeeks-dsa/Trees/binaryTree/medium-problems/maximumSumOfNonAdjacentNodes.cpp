int getMaxSumUtil(Node*root,map<Node*,int>&mp);

int getGrandChildren(Node*root,map<Node*,int>&mp){
    int sum = 0;
    if(root->left){
        sum+=getMaxSumUtil(root->left->left,mp)+getMaxSumUtil(root->left->right,mp);
    }
    if(root->right){
        sum+=getMaxSumUtil(root->right->left,mp)+getMaxSumUtil(root->right->right,mp);
    }
    return sum;
}

int getMaxSumUtil(Node*root,map<Node*,int>&mp){
    if(!root)return 0;
   if(mp.find(root)!=mp.end()){
       return mp[root];
   } 
   int incl = root->data+getGrandChildren(root,mp);
   int excl = getMaxSumUtil(root->left,mp)+getMaxSumUtil(root->right,mp);
   mp[root]=max(incl,excl);
   return mp[root];
}

//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{
    // Add your code here
    if(!root)return 0;
    map<Node*,int>mp;
    return getMaxSumUtil(root,mp);
}