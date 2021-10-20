class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          vector<int>v;
        for(int i=0;i<nums1.size();i++){
            int temp = nums1[i];
            int res = searchGreaterTemp(temp,nums2);
          
            v.push_back(res);
        }
        return v;
    }
    int searchGreaterTemp(int num,vector<int>nums2){
        int index;
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==num){
                index = i;
            }
        }
        for(int i=index;i<nums2.size();i++){
            if(num < nums2[i]){
                return nums2[i];
            }
        }
        return -1;
    }
};