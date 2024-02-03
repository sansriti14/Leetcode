class Solution {
    private int findMaxSum(int index, int[] arr, int k, int[] dp) {
        int n = arr.length;
        if(index >= n) return 0;
        if(dp[index] != 0) return dp[index];
        
        int max_ele = -1, max_sum = 0;
        for(int i = index; i < Math.min(index + k, n); i++) {
            max_ele = Math.max(max_ele, arr[i]);
            max_sum = Math.max(max_sum, max_ele * (i - index + 1) + findMaxSum(i + 1, arr, k , dp));
        }
        
        return dp[index] = max_sum;
    }
    
    
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];
        return findMaxSum(0, arr, k, dp);
    }
}