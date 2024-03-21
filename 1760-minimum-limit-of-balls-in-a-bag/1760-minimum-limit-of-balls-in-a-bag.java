class Solution {
    private int findMaxOperations(int[] nums, int penalty) {
        int max_operations = 0;
        for(int it: nums) {
            max_operations += (it - 1) / penalty;
        }
        
        return max_operations;
    }
    
    public int minimumSize(int[] nums, int maxOperations) {
        Arrays.sort(nums);
        
        int n = nums.length;
        int low = 1, high = nums[n - 1];
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int possible_max_operations = findMaxOperations(nums, mid);
            
            if(possible_max_operations > maxOperations) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
}