class Solution {  
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int day = n - 1; day >= 0; day--) {
            for (int num_transactions = 0; num_transactions <= k; num_transactions++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int& profit = dp[day][num_transactions][canBuy];

                    int doNothing = dp[day + 1][num_transactions][canBuy];

                    if (canBuy) {
                        profit = max(doNothing, -prices[day] + dp[day + 1][num_transactions][0]);
                    } else if (num_transactions < k) {
                        profit = max(doNothing, prices[day] + dp[day + 1][num_transactions + 1][1]);
                    }
                }
            }
        }

        return dp[0][0][1];
    }
};