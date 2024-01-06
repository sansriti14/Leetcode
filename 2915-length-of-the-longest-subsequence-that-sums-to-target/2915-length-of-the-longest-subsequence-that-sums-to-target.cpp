class Solution {
private:
    int findMaxLength(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        if(target == 0) return 0;
        
        if(target < 0 || index >= nums.size()) return -1e9;
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int not_take = findMaxLength(nums, target, index + 1, dp);
        int take = 1 + findMaxLength(nums, target - nums[index], index + 1, dp);
        
        return dp[index][target] = max(take, not_take);
    }
    
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        int max_length = findMaxLength(nums, target, 0, dp);
        return (max_length > 0) ? max_length : -1;
    }
};