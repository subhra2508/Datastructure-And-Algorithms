#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int a[1000000];
unordered_map<int, int> um;

int main() {

	int t;
	
	cin >> t;
	while(t--){
	    
	    int n, x;
	    cin >> n >> x;
	    
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	        um[a[i]]++;
	    }
	    
	    int count = 0;
	    bool flag = false;
	    for(int i = 0;i<n;i++){
	        if(x-a[i] >= 0){
	            if(x-a[i] == a[i]){
	                if(um[abs(a[i]-x)] > 1){
	                    cout << "Yes" << endl;
	                    // cout << "ye chla" << endl;
	                    flag = true;
	                    break;
	                }
	            }
	            else{
                    if(um[abs(a[i]-x)] >= 1){
        	            cout << "Yes" << endl;
        	            flag = true;
        	            break;
    	            }
	            }
	        }
	    }
	    
	    if(flag==false){
	        cout << "No" << endl;
	    }
	    
	    um.clear();
	}
	
	return 0;
}