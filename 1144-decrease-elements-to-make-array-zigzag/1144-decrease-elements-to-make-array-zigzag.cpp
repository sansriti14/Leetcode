class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even = 0, odd = 0;
        int n = nums.size();
        
		if (n <= 1) return 0;

        for (int i = 0; i < n; i+= 2) {
			if (i == 0) {
				if (nums[i] >= nums[i+1]) 
                    even += nums[i] - nums[i+1] + 1;
			} 
            
            else if (i == n - 1) {
				if (nums[i-1] <= nums[i]) 
                    even += nums[i] - nums[i-1] + 1;
			} 
            
            else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					even += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}
        
		for (int i = 1; i < n; i += 2) {
			if (i == n - 1) {
				if (nums[i-1] <= nums[i]) 
                    odd += nums[i]-nums[i-1]+1;
			} 
            
            else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					odd += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}

		return min(even, odd);
    }
};