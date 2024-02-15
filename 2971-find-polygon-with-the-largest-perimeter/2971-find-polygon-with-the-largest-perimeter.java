class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        
        long perimeter = -1;
        long curr_sum = 0;
        for(int i = 0; i < n; i++) {
            if(curr_sum > nums[i]) perimeter = (curr_sum + nums[i]);
            curr_sum += nums[i];
        }
        
        return perimeter;
    }
}