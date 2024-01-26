class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> dp(n);
        
        for(auto &it: nums) dp[it] += it;
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
        }
        
        return dp[n - 1];
    }
};