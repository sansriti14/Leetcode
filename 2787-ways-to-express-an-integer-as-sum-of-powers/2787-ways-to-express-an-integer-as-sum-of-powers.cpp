class Solution {
    int mod = 1e9 + 7;
    
private:
    int countNumWays(int num, int curr_sum, int n, int x, vector<vector<int>>& dp) {
        if(curr_sum > n) return 0;
        if(curr_sum == n) return 1;
        if(num > n) return 0;
        
        if(dp[num][curr_sum] != -1) return dp[num][curr_sum];
    
        int not_take = countNumWays(num + 1, curr_sum, n, x, dp);
        int take = 0;
        if(curr_sum + pow(num, x) <= n) {
            take = countNumWays(num + 1, curr_sum + pow(num, x), n, x, dp);
        }
        
        return dp[num][curr_sum] = (take + not_take) % mod;
    }
    
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp (n + 1, vector<int>(n + 1, -1));
        return countNumWays(1, 0, n, x, dp);
    }
};