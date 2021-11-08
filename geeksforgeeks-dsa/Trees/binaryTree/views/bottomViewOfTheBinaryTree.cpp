class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,pair<int,int>>mp;
        bottomViewUtil(root,0,0,mp);
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second.first);
        }
        return v;
    }
    void bottomViewUtil(Node*root,int dist,int level,auto &mp){
        if(root==NULL)return;
        if(level >= mp[dist].second){
            mp[dist]={root->data,level};
        }
        bottomViewUtil(root->left,dist-1,level+1,mp);
        bottomViewUtil(root->right,dist+1,level+1,mp);
    }
};