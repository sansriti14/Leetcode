class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;
        
        int prev_finish_time = customers[0][0] + customers[0][1];
        long total_wt = customers[0][1];
        
        for (int i = 1; i < n; i++) {
            total_wt += customers[i][1];
            total_wt += Math.max(0, prev_finish_time - customers[i][0]);
            
            prev_finish_time = Math.max(prev_finish_time, customers[i][0]) + customers[i][1];
        }
        
        return (double)total_wt / n;
    }
}