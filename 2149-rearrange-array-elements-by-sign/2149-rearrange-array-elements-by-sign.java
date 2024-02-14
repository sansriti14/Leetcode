class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        int positive_index = 0, negative_index = 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[positive_index] = nums[i];
                positive_index += 2;
            }
            
            else {
                ans[negative_index] = nums[i];
                negative_index += 2;
            }
        }
        
        return ans;
    }
}