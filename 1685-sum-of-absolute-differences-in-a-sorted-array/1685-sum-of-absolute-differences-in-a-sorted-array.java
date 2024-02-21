class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int result[] = new int[n];
        
        for(int i = 1; i < n; i++) {
            result[0] += (nums[i] - nums[0]);
        }
        
        for(int j = 1; j < n; j++) {
            result[j] = result[j - 1] + (nums[j] - nums[j - 1]) * j - (nums[j] - nums[j - 1]) * (n - j);
        }
        
        return result;        
    }
}