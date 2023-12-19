class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for(int i=0; i<n; i++) {
            if(dp[i] != 0) {
                for(int j = i+1; j < n && j <= i + nums[i]; j++) 
                    dp[j] = 1;
            } 
        }
        
        return dp[n-1];
    }
};