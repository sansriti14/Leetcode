class Solution {
    private int countAtMost(int[] nums, int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        
        int num_subarrays = 0;
        int curr_distinct = 0;
        
        int i = 0, j = 0;
        while(j < nums.length) {
            freq.put(nums[j], freq.getOrDefault(nums[j], 0) + 1);
            if(freq.get(nums[j]) == 1) curr_distinct++;
            
            while(curr_distinct > k) {
                freq.put(nums[i], freq.get(nums[i]) - 1);
                if(freq.get(nums[i]) == 0) curr_distinct--;
                i++;
            }
            
            j++;
            num_subarrays += (j - i + 1);
        }
        
        return num_subarrays;
    }  
    
    public int subarraysWithKDistinct(int[] nums, int k) {
        return countAtMost(nums, k) -  countAtMost(nums, k - 1);
    }
} 