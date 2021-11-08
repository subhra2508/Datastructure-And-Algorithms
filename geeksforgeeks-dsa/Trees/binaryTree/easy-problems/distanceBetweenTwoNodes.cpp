int distanceBetweenNodes(Node*root,val,distance=0){
	if(root==NULL)return -1;
	if(root->data == val)return distance;
	int d = distanceBetweenNodes(root->left,val,distance+1);
	if(d!=-1)return d;
	d=distanceBetweenNodes(root->right,val,distance+1);
	return d;

}
// shortest path between two nodes when 2 nodes data are given
#include<bits/stdc++.h>
using namespace std;
vector<int>v1;
vector<int>v2;

//to find the element
int BinarySearch(int x){
	int low = 0;
	int high = v2.size()-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(v2[mid] == x){
			return mid;
		}
		else if(v2[mid] > x){
			high = mid -1;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}
//function to make ancestors of first node
void makeAncestorNode1(int x){
	v1.clear();
	while(x){
		v1.push_back(x);
		x/=2;
	}
	reverse(v1.begin(),v1.end());
}
void makeAncestorNode2(int x){
	v2.clear();
	while(x){
		v2.push_back(x);
		x/=2;
	}
	reverse(v2.begin(),v2.end());
}

int Distance(){
	for(int i=v1.size()-1;i>=0;i--){
		int x = BinarySearch(v1[i]);
		if(x!=-1){
			return v1.size()-1-i+v2.size()-1-x;
		}
	}
}


int main(){
	makeAncestorNode1(node1);
	makeAncestorNode2(node2);
	Distance();
}