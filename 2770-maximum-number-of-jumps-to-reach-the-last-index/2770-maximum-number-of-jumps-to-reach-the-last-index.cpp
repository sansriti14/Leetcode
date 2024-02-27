class Solution {
private:
    int findMaxJumps(int i, vector<int>& nums, int target, vector<int>& dp) {
        int n = nums.size();
        if(i == n - 1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int maxJumps = -1e9;
        for(int j = i + 1; j < n; j++) {
            if(abs(nums[j] - nums[i]) <= target) {
                maxJumps = max(maxJumps, 1 + findMaxJumps(j, nums, target, dp));
            }
        }
        
        return dp[i] = maxJumps;
    }
    
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp (n + 1, -1);
        
        int maxJumps = findMaxJumps(0, nums, target, dp);
        
        
        return (maxJumps > 0) ? maxJumps : -1;
    }
};