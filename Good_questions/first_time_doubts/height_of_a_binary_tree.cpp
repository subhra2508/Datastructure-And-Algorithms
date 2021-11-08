int height(Node*root){
	if(node==NULL){
		return 0;
	}
	else{
		queue<Node*>q;
		q.push(root);
		int height=0;
		while(1){
			int count_node=q.size();
			if(count_node==0){
				return height;
			}
			height++;
			while(node_count>0){
               Node*temp=q.front();
               q.pop();
               if(root->left)q.push(root->left);
               if(root->right)q.push(root->right);
               node_count--;
			}
		}
	}

}