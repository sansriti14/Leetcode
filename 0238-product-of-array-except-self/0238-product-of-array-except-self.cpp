class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        int countZero = 0;
        long long product = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                product *= nums[i];
            }
            
            else countZero++;
        }
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            if((countZero > 0 && nums[i] != 0) || countZero > 1) {
                ans[i] = 0;
            }
            
            else ans[i] = (nums[i] == 0) ? product : product / nums[i];
        }
        
        return ans;
    }
};