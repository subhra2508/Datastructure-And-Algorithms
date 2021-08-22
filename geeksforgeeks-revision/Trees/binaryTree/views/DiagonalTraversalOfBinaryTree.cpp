//for left child diagonal distance d = d+1;
// for every right child, d = d

void printDiagonal(Node* node, int diagonal, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // insert the current node into the current diagonal
    map[diagonal].push_back(node->data);
 
    // recur for the left subtree by increasing diagonal by 1
    printDiagonal(node->left, diagonal + 1, map);
 
    // recur for the right subtree with the same diagonal
    printDiagonal(node->right, diagonal, map);
}
 
// Function to print the diagonal elements of a given binary tree
void printDiagonal(Node* root)
{
    // create an empty map to store the diagonal element in every slope
    unordered_map<int, vector<int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printDiagonal(root, 0, map);
 
    // traverse the map and print the diagonal elements
    int temp = 0;
 
    for (int i = 0; i < map.size(); i++)
    {
        for (int i: map[i]) {
            cout << i << ' ';
        }
        cout << endl;
    }
}
