int value(Node*root,int x,int &count){
    if(root == NULL)return 0;
    int ls = value(root->left,x,count);
    int rs = value(root->right,x,count);
    int sum = ls+rs+root->data ;
    if(sum == x)count++;
    return sum;
}
//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0;
	if(root == NULL)return 0;
	value(root,X,count);
	return count;
}