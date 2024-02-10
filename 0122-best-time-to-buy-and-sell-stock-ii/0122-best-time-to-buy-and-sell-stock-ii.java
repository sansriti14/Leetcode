class Solution {
    public int maxProfit(int[] prices) {
        int max_profit = 0;
        
        for(int i = 1; i < prices.length; i++) 
            max_profit += Math.max(prices[i] - prices[i - 1], 0);
        
        return max_profit;
    }
}