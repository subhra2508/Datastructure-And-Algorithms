// Given a tree with N nodes rooted at 1. Each node labeled with a value arr[i]. 
//The task is to find the absolute difference between the sum of values of nodes at even level and odd level

// Note: All the nodes are numbered from 1 to N.

// Input:
// 1. The first line of the input contains a single integer T denoting the number of test cases. 
//The description of T test cases follows.
// 2. The first line of each test case contains a single integer N.
// 3. The next line contains N space-separated positive integers represents the node value.
// 4. Next N-1 lines contain two space-separated integers u and v, represents an edge in between them


// Output: For each test case, print the answer


#include<bits/stdc++.h>
using namespace std;

int n,odd,even,x,arr[N];
vector<int>gr[N];

void dfs(int ch,int par,int lvl){
	if(lvl%2==0){
		even +=arr[ch];
	}
	else{
		odd+=arr[ch];
	}
	for(auto i:gr[ch]){
		if(i!=par){
			dfs(i,ch,lvl+1);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			gr[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		odd = 0;
		even = 0;
		dfs(1,0,1);
		cout<<abs(odd-even)<<"\n";
	}
	return 0;

}