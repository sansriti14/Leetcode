class Solution {
private:
    int findMaxAmount(int index, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        
        int not_rob = findMaxAmount(index + 1, nums, dp);
        int rob = max(not_rob, nums[index] + findMaxAmount(index + 2, nums, dp));
        
        return dp[index] = max(rob, not_rob);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp (n + 1, -1);
        
        return findMaxAmount(0, nums, dp);
    }
};