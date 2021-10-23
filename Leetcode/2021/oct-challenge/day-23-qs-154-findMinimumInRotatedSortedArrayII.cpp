class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
         for(int i=0;i<nums.size()-1;i++){
             if(nums[i]>nums[i+1]){
                 res = nums[i+1];
             }
         }
        return res;
    }
};



binary search :::
class Solution {
    public int findMin(int[] nums) {
        int lo = 0, hi = nums.length - 1;
        
        if (nums[lo] < nums[hi]) return nums[lo];
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                hi--;
            }
        }
        
        return nums[hi];
    }
}