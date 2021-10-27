class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};


Using Dutch Flag Algo (RunTime : 0 ms (100%) & Memory Usage : 91.24%)

Explanation:

Initailize three pointers zero, one and two.
Traverse pointer two in backward.
when 2 is encountered, just move to next step by decreamenting pointer two.
when 1 is encountered , swap with pointer one and increament pointer one
when 0 is encountered , swap with pointer zero and increament pointer zero.
Repeated from Step 3 until pointer one and two cross each other (means sorted).
CODE:

void sortColors(vector<int>& nums) {
        //pointers initailization.
        int zero = 0,one = 0,two =nums.size()-1;
        //move pointer two in reverse order
        
        while(one<=two){
            
            if(nums[two]==2){//means '2' is in correct place, so moving to previous element
                two--;
            }
            else if(nums[two]==1){//swaping element with pointer one
                nums[two]=nums[one];
                nums[one] = 1;
                one++;
            }
            else{//swaping element with pointer zero
                nums[two] = nums[zero];
                nums[zero]=0;
                
                if(zero==one)//when no ones encounter, zero and one will be same, so increasing one pointer when zero pointer is increasing.
                    one++;
                zero++;
            } 
        }
    }