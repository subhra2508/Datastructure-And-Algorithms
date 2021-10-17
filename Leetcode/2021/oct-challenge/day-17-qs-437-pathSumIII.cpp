class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int>mp;
        int count = 0;
        int sum = 0;
        pathSumUtil(root,targetSum,sum,count,mp);
        return count ;
        
    }
    void pathSumUtil(TreeNode*root,int targetSum,int sum,int &count,unordered_map<int,int>&mp){
        if(!root)return ;
        int res = 0;
        sum+=root->val;
        if(sum == targetSum)count++;
        if(mp.find(sum-targetSum)!=mp.end()){
            count +=mp[sum-targetSum];
        }
        mp[sum]++;
        pathSumUtil(root->left,targetSum,sum,count,mp);
        pathSumUtil(root->right,targetSum,sum,count,mp);
        mp[sum]--;
        
    }
};

//the above one is the O(n) approach


//o(n2) approach 
int total = 0;

int pathSum(TreeNode*root,int targetSum){
    if(root==NULL)return 0;

    findPathSum(root,sum,0);
    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);
    return total;
}

void findPathSum(TreeNode*root,int targetSum,int currentSum){
    if(root==NULL)return ;
    currentSum += root->val;
    if(currentSum == targetSum){
        total++;
    }
    findPathSum(root->left,targetSum,currentSum);
    findPathSum(root->right,targetSum,currentSum);
}






















