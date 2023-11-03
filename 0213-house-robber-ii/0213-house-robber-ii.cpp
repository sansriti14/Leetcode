class Solution {
private:
    int findMaxAmount(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return dp[n-1];
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));
        
        vector<int> exclude_first, exclude_last;
        for(int i = 0; i < n; i++) {
            if(i != 0) exclude_first.push_back(nums[i]);
            if(i != n-1) exclude_last.push_back(nums[i]);
        }
        
        return max(findMaxAmount(exclude_first), findMaxAmount(exclude_last));
    }
};