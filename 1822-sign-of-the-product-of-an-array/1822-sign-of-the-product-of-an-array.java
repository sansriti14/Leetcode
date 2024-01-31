class Solution {
    public int arraySign(int[] nums) {
        int n = nums.length;
        int negative_count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) negative_count++;
            if(nums[i] == 0) return 0;
        }
        
        return (negative_count % 2 == 0) ? 1 : -1;
    }
}