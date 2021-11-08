#include<bits/stdc++.h>
using namespace std;
#define ll long long
//typedef pair<ll,ll>pr;
struct hash_pair{
	template<class T1,class T2>
	size_t operator()(const pair<T1,T2>&p) const
	{
       auto hash1=hash<T1>{}(p.first);
       auto hash2=hash<T2>{}(p.second);
       return hash1^hash2;
          
	}     
};
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		ll flag=0;
		ll result=INT_MAX;
        vector<pair<ll,ll>>v;
		unordered_map<pair<ll,ll>,bool,hash_pair>ump;
		map<ll,pair<ll,ll>>mp;
		for(ll i=0;i<n-1;i++){
			for(ll j=0;j<n;j++){
				if(ump.find({i,j})==ump.end()){
                      ll sum=arr[i]+arr[j];
                      if(mp.find(sum)!=mp.end()){
                      	flag=1;
                      	ll first_index=mp[sum].first;
                      	ll second_index=mp[sum].second;
                      	ll s=min(first_index,second_index);
                      	ll t=min(i,j);
                      	ll min_value=min(s,t);
                      	if(min_value<result){
                      		result=min_value;
                      		 v.clear();
                      		 if(s<t){
                      		 	v.push_back({first_index,second_index});
                      		 	v.push_back({i,j});
                      		 }else{
                      		 	v.push_back({i,j});
                      		 	v.push_back({first_index,second_index});
                      		 }
                      	}
                      }
                      mp[sum]={i,j};
				}

			}
		}
		if(flag==1){
		for(auto &x:v){
             cout<<x.first<<" "<<x.second<<" ";
		}
	}
	else{
        cout<<"no pairs";
		
	}
	cout<<endl;
	}
}