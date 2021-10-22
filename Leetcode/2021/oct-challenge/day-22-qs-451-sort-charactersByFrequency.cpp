class Solution {
public:
     static bool compare(const pair<char,int>&p1,const pair<char,int>&p2){
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>>v;
        
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            v.push_back({itr->first,itr->second});
        }
        sort(v.begin(),v.end(),compare);
        string result="";
        for(int i=0;i<v.size();i++){
            int count = v[i].second;
            
            while(count--){
                result+=v[i].first;
            }
        }
        return result;
    }
};