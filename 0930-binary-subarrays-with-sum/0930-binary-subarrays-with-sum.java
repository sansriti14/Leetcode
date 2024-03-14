class Solution {
    private int countAtMost(int []nums, int k) {
        if(k < 0) return 0;
        
        int n = nums.length;
        int i = 0, j = 0;
        
        int numSubarrays = 0;
        int currSum = 0;
        while(j < n) {
            currSum += nums[j];
            
            while(i < n && currSum > k) {
                currSum -= nums[i++];
            }
            
            numSubarrays += (j - i + 1);
            j++;
        }
        
        return numSubarrays;
    }
    
    public int numSubarraysWithSum(int[] nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
}