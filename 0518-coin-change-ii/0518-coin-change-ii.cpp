class Solution {
private:
    int findNumCombinations(int amount, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if(n == 0) return 0;
        if(amount == 0) return 1;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        
        if(coins[n-1] > amount) {
            dp[n][amount] = findNumCombinations(amount, n-1, coins, dp);
            return dp[n][amount];
        }
        
        int take = findNumCombinations(amount - coins[n-1], n, coins, dp);
        int not_take = findNumCombinations(amount, n-1, coins, dp);
        
        return dp[n][amount] = take + not_take;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        if(amount == 0) return 1;
        
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n+2, vector<int> (amount+2, -1));
        return findNumCombinations(amount, n, coins, dp);
    }
};