class Solution {
private:
    int findLIS(vector<int>& nums, int prev_index, int curr_index, vector<vector<int>>& dp) {
        if(curr_index == nums.size()) return 0;
        
        if(dp[prev_index + 1][curr_index] != -1) return dp[prev_index + 1][curr_index];
        
        int not_take = 0, take = 0;
        not_take = findLIS(nums, prev_index, curr_index + 1, dp);
        
        if(prev_index == -1 || nums[curr_index] > nums[prev_index]) {
            take = max(not_take, 1 + findLIS(nums, curr_index, curr_index + 1, dp));
        }
        
        return dp[prev_index + 1][curr_index] = max(take, not_take);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n+1, vector<int> (n, -1));
        return findLIS(nums, -1, 0, dp);
    }
};