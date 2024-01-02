class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        
        int leftSum  = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            total_sum -= nums[i];
            
            if(leftSum == total_sum)
                return i;
            
            leftSum += nums[i];
        }
        
        return -1;
    }
};