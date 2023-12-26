class Solution {   
private:
    int findWays(int n, int k, int target, vector<vector<int>>& dp) {
        if(n == 0 && target == 0) return 1;
        if(n <= 0 || target <= 0) return 0;
        
        if(dp[n][target] != -1) return dp[n][target];

        int numWays = 0, mod = 1e9 + 7;
        for(int i = 1; i <= k; i++) {
                numWays = (numWays % mod + (findWays(n-1, k, target-i, dp)) % mod) % mod;
        }

        return dp[n][target] = numWays;
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return findWays(n, k, target, dp);
    }
};