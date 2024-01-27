class Solution {
private:
    int countPairs(int n, int k, vector<vector<int>>& dp) {
        if(k <= 0) return !k;
        if(n <= 0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mod = 1e9 + 7;
        dp[n][k] = (countPairs(n - 1, k, dp) + countPairs(n, k - 1, dp)) % mod;
        return dp[n][k] = (dp[n][k] - countPairs(n - 1, k - n, dp) + mod) % mod;
    }
    
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp (n + 1, vector<int> (k + 1, -1));
        return countPairs(n, k, dp);
    }
};