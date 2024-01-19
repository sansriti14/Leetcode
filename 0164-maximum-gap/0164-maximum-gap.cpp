class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        
        sort(begin(nums), end(nums));
        
        int max_diff = 0;
        for(int i = 0; i < n - 1; i++) {
            max_diff = max(max_diff, nums[i + 1] - nums[i]);
        }
        
        return max_diff;
    }
};