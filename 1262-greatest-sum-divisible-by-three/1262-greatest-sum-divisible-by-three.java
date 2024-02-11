class Solution {
    private int findMaxSum(int index, int rem, int[] nums, int dp[][]) {
        if(index >= nums.length) return (rem == 0) ? (int)0 : (int)-1e9;
        if(dp[index][rem] != -1) return dp[index][rem];
        
        int not_pick = findMaxSum(index + 1, rem, nums, dp);
        int pick = nums[index] + findMaxSum(index + 1, (rem + nums[index]) % 3, nums, dp);
        
        return dp[index][rem] = Math.max(not_pick, pick);
    }
    
    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int dp[][] = new int[n + 1][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }
        
        return findMaxSum(0, 0, nums, dp);
    }
}