class Solution {   
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        
        int mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            for(int currSum = 1; currSum <= target; currSum++) {
                for(int num = 1; num <= k; num++) {
                    if(num <= currSum)
                        dp[i][currSum] = (dp[i][currSum] + dp[i-1][currSum - num]) % mod;
                }
            }
        }
        
        return dp[n][target];
    }
};