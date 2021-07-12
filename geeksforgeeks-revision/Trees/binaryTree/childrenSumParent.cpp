class solution{
public:
	int isSumProperty(Node*root){
		if(!root || !root->left && !root->right)return 1;
		int left_data = root->left->data;
		int right_data = root->right->data;
		if(root->data == left_data+right_data&&isSumProperty(root->left)&&isSumProperty(root->right))return 1;
		else return 0;
	}
}