class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int curr_sum = 0;
	    int max_sum = 0;
	    int n = s.length();
	    for(int i=0;i<n;i++){
	        curr_sum +=(s[i] == '0'? 1 : -1);
	        if(curr_sum < 0){
	            curr_sum = 0;
	        }
	        max_sum = max(max_sum,curr_sum);
	        
	    }
	    return max_sum == 0 ? -1:max_sum;
	}
};