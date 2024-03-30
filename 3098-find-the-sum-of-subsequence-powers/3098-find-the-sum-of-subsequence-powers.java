class Solution {
    int mod = (int)1e9 + 7;
    
    private int findSumOfPowers(int index, int prevIndex, int currDiff, int[] nums, int k, Map<String, Integer> mp) {
        if (index == nums.length) return (k == 0) ? currDiff % mod : 0;

        String key = index + "$" + currDiff + "$" + k + "$" + prevIndex;
        if (mp.containsKey(key)) return mp.get(key);
     
        int not_take = findSumOfPowers(index + 1, prevIndex, currDiff, nums, k, mp) % mod;
          
        currDiff = (prevIndex == -1) ? currDiff : Math.min(currDiff, Math.abs(nums[index] - nums[prevIndex]));
            
        int take = findSumOfPowers(index + 1, index, currDiff, nums, k - 1, mp) % mod;
        
        int total = (take + not_take) % mod;
        mp.put(key, (int)(take + not_take) % mod);
        
        return total;
    }
    
    public int sumOfPowers(int[] nums, int k) {
        Arrays.sort(nums);
        
        Map<String, Integer> mp = new HashMap<>();
        
        return findSumOfPowers(0, -1, Integer.MAX_VALUE, nums, k, mp);
    }
}
