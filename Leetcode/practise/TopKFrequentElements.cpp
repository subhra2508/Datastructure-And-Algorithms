#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
  return p1.second < p2.second;
}
vector<int>solve(vector<int>&nums,int k){
     vector<int>v;
    map<int,int>mp;
    for(int i =0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    vector<pair<int,int>>vp;
    int j = 0;
    for(auto &itr:mp){
        vp[j].first = itr.first;
        vp[j].second = itr.second;
        j++;
    }
    sort(vp.begin(),vp.end(),cmp);
    for(int i =0 ; i<vp.size()&&i<=k;i++){
        int x = vp[i].first;
        v.push_back(x);
    }
    return v;
}

int main(){
  vector<int>nums{1,1,1,2,2,3};
}




