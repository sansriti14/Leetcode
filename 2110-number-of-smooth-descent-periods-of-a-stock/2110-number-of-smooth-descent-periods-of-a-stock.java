class Solution {
    public long getDescentPeriods(int[] prices) {
        long curr = 0;
        long descent_days = 0;
        
        for (int i = 0; i < prices.length; i++) {
            if (i != 0 && prices[i - 1] - prices[i] == 1) curr++;
            else curr = 1;
            
            descent_days += curr;
        }
        
        return descent_days;
    }
}