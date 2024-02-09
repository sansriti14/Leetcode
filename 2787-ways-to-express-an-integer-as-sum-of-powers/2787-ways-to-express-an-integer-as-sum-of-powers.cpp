class Solution {
    int mod = 1e9 + 7;
    
private:
    int countNumWays(int num, int n, int x, vector<vector<int>>& dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(num > n) return 0;
        
        if(dp[num][n] != -1) return dp[num][n];
    
        int not_take = countNumWays(num + 1, n, x, dp);
        int take = 0;
        if(n - pow(num, x) >= 0) {
            take = countNumWays(num + 1, n - pow(num, x), x, dp);
        }
        
        return dp[num][n] = (take + not_take) % mod;
    }
    
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp (n + 1, vector<int>(n + 1, -1));
        return countNumWays(1, n, x, dp);
    }
};