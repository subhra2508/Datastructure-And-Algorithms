#include <bits/stdc++.h>
#define endll "\n";
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int d=0;
        unordered_map<char,int> mp1,mp;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        d=mp1.size();
        int c1=0,j=0,max1=s.length();
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                c1++;
            }
            mp[s[i]]++;
            while(mp[s[j]]>1){
                mp[s[j]]--;
                j++;
            }
            if(c1==d){
                max1=min(max1,i-j+1);
            }
        }
        cout<<max1<<endll;
    }
    return 0;
}

/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        int arr[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        for(int i=0;i<s.length();i++){
            ++arr[s[i]-'a'];
        }
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                ++cnt;
            }
        }
        int present[26];
        for(int i=0;i<26;i++)
            present[i]=0;
        
        int l=0;
        int k=0;
        int mn=s.length();
        for(int i=0;i<s.length();i++){
            if(present[s[i]-'a']==0){
                ++k;
            }
            ++present[s[i]-'a'];
        
        
        if(k==cnt){
            while(l<=i&&present[s[l]-'a']>1){
                
                --present[s[l]-'a'];
                ++l;
            } 
            mn=min(mn,i-l+1);
        }
        
    }
       cout<<mn<<endl;
    }
    return 0;
}
*/