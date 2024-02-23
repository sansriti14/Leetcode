class Solution {
private:
    int findMaxProfit(int day, int num_transactions, int canBuy, vector<int>&price, vector<vector<vector<int>>>& dp) {
        if(day == price.size() || num_transactions == 2) return 0;

        if(dp[day][num_transactions][canBuy] != -1) return dp[day][num_transactions][canBuy];

        int profit = 0;

        int doNothing = findMaxProfit(day + 1, num_transactions, canBuy, price, dp);

        if(canBuy) {
            profit += max(doNothing, -price[day] + findMaxProfit(day + 1, num_transactions, 0, price, dp));
        }

        else profit += max(doNothing, price[day] + findMaxProfit(day + 1, num_transactions + 1, 1, price, dp));

        return dp[day][num_transactions][canBuy] = profit;
    }
    
public:
    int maxProfit(vector<int>&price){
        int n = price.size();
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (3, vector<int> (2, -1)));

        return findMaxProfit(0, 0, 1, price, dp);
    }
};