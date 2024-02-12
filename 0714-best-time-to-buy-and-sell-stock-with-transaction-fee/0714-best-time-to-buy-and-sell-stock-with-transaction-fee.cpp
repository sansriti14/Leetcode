class Solution {
private:
    int findMaxProfit(int curr_day, bool canBuy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if(curr_day == prices.size()) return 0;
        if(dp[curr_day][canBuy] != -1) return dp[curr_day][canBuy];
        
        int profit = 0;
        int doNothing = findMaxProfit(curr_day + 1, canBuy, prices, fee, dp);
        if(canBuy) {
            profit = max(doNothing, findMaxProfit(curr_day + 1, !canBuy, prices, fee, dp) - prices[curr_day] - fee);
        }
        
        else profit = max(doNothing, findMaxProfit(curr_day + 1, !canBuy, prices, fee, dp) + prices[curr_day]);
        
        return dp[curr_day][canBuy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        bool canBuy = true;
        vector<vector<int>> dp (n + 1, vector<int> (2, -1));
        return findMaxProfit(0, canBuy, prices, fee, dp);
    }
};