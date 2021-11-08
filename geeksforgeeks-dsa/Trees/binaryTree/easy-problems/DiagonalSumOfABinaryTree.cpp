// d = diagonal_distance;
// important
// for root , d = 0;
// for leftchild d=d_parent+1;
// for rightchild d = d_parent;


class solution {
public:
	vector<int>diagonalSum(Node*root){
		vector<int>v;
		map<int,int>mp;
		diagonalSumUtil(root,0,mp);
		for(auto itr = mp.begin();itr!=mp.end();itr++){
			v.push_back(itr->second);
		}
		return v;
	}
	void diagonalSumUtil(Node*root,int level,map<int,int>&mp){
		if(!root)return;
		mp[level]+=root->data;
		diagonalSumUtil(root->left,level+1,mp);
		diagonalSumUtil(root->right,level,mp);
	}

}