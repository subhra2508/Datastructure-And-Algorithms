class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        // Your code here
        unordered_map<int,Node*>mp;
        for(int i=0;i<N;i++){
            mp[i]=new Node(i);
        }
        Node*root = NULL;
        for(int i=0;i<N;i++){
            if(parent[i]==-1){
                root = mp[i];
            }
            else{
                Node*ptr = mp[parent[i]];
                if(ptr->left){
                    ptr->right = mp[i];
                }
                else{
                    ptr->left = mp[i];
                }
            }
        }
        return root;
    }
};