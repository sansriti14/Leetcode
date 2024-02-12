class Solution {
    private int findMaxProfit(int curr_day, int canBuy, int[] prices, int fee, int dp[][]) {
        if(curr_day == prices.length) return 0;
        if(dp[curr_day][canBuy] != -1) return dp[curr_day][canBuy];
        
        int doNothing = findMaxProfit(curr_day + 1, canBuy, prices, fee, dp);
        int profit = 0;
        if(canBuy == 1) {
            profit = Math.max(doNothing, findMaxProfit(curr_day + 1, 0, prices, fee, dp) - prices[curr_day] - fee);
        }
        
        else {
             profit = Math.max(doNothing, findMaxProfit(curr_day + 1, 1, prices, fee, dp) + prices[curr_day]);
        }
        
        return dp[curr_day][canBuy] = profit;
    }
    
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int canBuy = 1;
        int dp[][] = new int[n + 1][2];
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        return findMaxProfit(0, canBuy, prices, fee, dp);
    }
}