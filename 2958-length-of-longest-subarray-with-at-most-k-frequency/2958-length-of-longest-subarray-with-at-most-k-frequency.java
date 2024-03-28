class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        
        int maxLength = 0;
        while (j < n) {
            while (j < n && mp.getOrDefault(nums[j], 0) + 1 <= k) {
                mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
                j++;
            }
            
            maxLength = Math.max(maxLength, j - i);
            
            mp.put(nums[i], mp.get(nums[i]) - 1);
            i++;
        }
        
        return maxLength;
    }
}