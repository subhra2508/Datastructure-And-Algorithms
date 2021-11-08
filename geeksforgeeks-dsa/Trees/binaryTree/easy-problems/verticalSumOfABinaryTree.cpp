class soluction{
public:
	vector<int>verticalSum(Node*root){
		vector<int>v;
		map<int,int>mp;
		veritcalSumUtil(root,0,mp);
		for(auto itr = mp.begin(),itr!=mp.end();itr++){
			v.push_back(itr->second);
		}
		return v;
	}
	void verticalsumUtil(Node*root,int level,map<int,int>&mp){
		if(!root)return nullptr;
		verticalsumUtil(root->left,level-1,mp);
		mp[level]+=root->data;
		verticalsumUtil(root->right,level+1,mp);
	}
}