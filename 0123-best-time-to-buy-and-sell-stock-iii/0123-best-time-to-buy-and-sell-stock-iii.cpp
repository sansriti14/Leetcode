class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));

        for (int day = n - 1; day >= 0; day--) {
            for (int num_transactions = 0; num_transactions <= 2; num_transactions++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int& profit = dp[day][num_transactions][canBuy];

                    int doNothing = dp[day + 1][num_transactions][canBuy];

                    if (canBuy) {
                        profit = max(doNothing, -price[day] + dp[day + 1][num_transactions][0]);
                    } else if (num_transactions < 2) {
                        profit = max(doNothing, price[day] + dp[day + 1][num_transactions + 1][1]);
                    }
                }
            }
        }

        return dp[0][0][1];
    }
};
