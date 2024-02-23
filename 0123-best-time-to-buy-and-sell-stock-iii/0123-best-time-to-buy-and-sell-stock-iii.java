class Solution {
    private int findMaxProfit(int day, int num_transactions, int canBuy, int[] price, int dp[][][]) {
        if(day == price.length || num_transactions == 2) return 0;

        if(dp[day][num_transactions][canBuy] != -1) return dp[day][num_transactions][canBuy];

        int profit = 0;

        int doNothing = findMaxProfit(day + 1, num_transactions, canBuy, price, dp);

        if(canBuy == 1) {
            profit += Math.max(doNothing, -price[day] + findMaxProfit(day + 1, num_transactions, 0, price, dp));
        }

        else profit += Math.max(doNothing, price[day] + findMaxProfit(day + 1, num_transactions + 1, 1, price, dp));

        return dp[day][num_transactions][canBuy] = profit;
    }
    
    public int maxProfit(int[] price) {
        int n = price.length;
        
        int dp[][][] = new int[n + 1][3][2];
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return findMaxProfit(0, 0, 1, price, dp);
    }
}