class Solution {
    private int countPairs(int n, int k, int dp[][]) {
        if(k <= 0) return k != 0 ? 0 : 1;
        if(n <= 0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mod = (int)1e9 + 7;
        dp[n][k] = (countPairs(n - 1, k, dp) + countPairs(n, k - 1, dp)) % mod;
        return dp[n][k] = (dp[n][k] - countPairs(n - 1, k - n, dp) + mod) % mod;
    }
    
    public int kInversePairs(int n, int k) {
        int dp[][] = new int[n + 1][k + 1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) 
                dp[i][j] = -1;
        }
        
        return countPairs(n, k, dp);
    }
}

    