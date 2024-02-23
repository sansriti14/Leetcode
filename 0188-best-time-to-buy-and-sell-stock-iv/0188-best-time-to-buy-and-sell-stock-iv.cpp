class Solution {
private:
    int findMaxProfit(int day, int num_transactions, int canBuy, int k, vector<int>&prices, vector<vector<vector<int>>>& dp) {
        if(day == prices.size() || num_transactions == k) return 0;

        if(dp[day][num_transactions][canBuy] != -1) return dp[day][num_transactions][canBuy];

        int profit = 0;

        int doNothing = findMaxProfit(day + 1, num_transactions, canBuy, k, prices, dp);

        if(canBuy) {
            profit += max(doNothing, -prices[day] + findMaxProfit(day + 1, num_transactions, 0, k, prices, dp));
        }

        else profit += max(doNothing, prices[day] + findMaxProfit(day + 1, num_transactions + 1, 1, k, prices, dp));

        return dp[day][num_transactions][canBuy] = profit;
    }    
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (k, vector<int> (2, -1)));

        return findMaxProfit(0, 0, 1, k, prices, dp);
    }
};