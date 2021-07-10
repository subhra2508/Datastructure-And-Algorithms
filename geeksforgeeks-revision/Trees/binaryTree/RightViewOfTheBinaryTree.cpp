 void rightView(struct Node*root){
 	int max_level = 0;
 	rightViewUtil(root,1,&max_level);
 }

 void rightViewUtil(struct Node*root,int level,int *max_level){
 	if(root = NULL)return ;
 	if(*max_level < level){
 		cout<<root->data;
 		*max_level = level;
 	}
 	rightViewUtil(root->right,level+1,max_level);
 	rightViewUtil(root->left,level+1,max_level);
 }
// -------------------------------------------------------------------------------------- 
 //using map
 void printRightView(Node* root, int level, auto &map)
{
    if (root == nullptr) {
        return;
    }
 
    // insert the current node and level information into the map
    map[level] = root->key;
 
    // recur for the left subtree before the right subtree
    printRightView(root->left, level + 1, map);
    printRightView(root->right, level + 1, map);
}
 
// Function to print the right view of a given binary tree
int printRightView(Node* root)
{
    // create an empty map to store the last node for each level
    unordered_map<int, int> map;
 
    // traverse the tree and fill the map
    printRightView(root, 1, map);
 
    // iterate through the map and print the right view
    for (int i = 1; i <= map.size(); i++) {
        cout << map[i] << " ";
    }
}