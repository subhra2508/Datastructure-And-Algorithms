#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void diagonalSumCount(Node*root,int diagonal,unordered_map<int,int>&mp){
	if(root==NULL)return ;
	mp[diagonal]+=root->data;
	diagonalSumCount(root->left,diagonal+1,mp);
	diagonalSumCount(root->right,diagonal,mp);
}
vector<int>diagonalSum(Node*root){
	unordered_map<int,int>mp;
	diagonalSumCount(root,0,mp);
	for(int i=0;i<mp.size();i++){
		v.push_back(mp[i]);
	}
}
int main(){

}