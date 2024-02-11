class Solution {
private:
    int findMaxSum(int index, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if(index >= nums.size()) return (rem == 0) ? 0 : -1e9;
        if(dp[index][rem] != -1) return dp[index][rem];
        
        int not_pick = findMaxSum(index + 1, rem, nums, dp);
        int pick = nums[index] + findMaxSum(index + 1, (rem + nums[index]) % 3, nums, dp);
        
        return dp[index][rem] = max(not_pick, pick);
    }
    
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n + 1, vector<int> (3, -1));
        return findMaxSum(0, 0, nums, dp);
    }
};