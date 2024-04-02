class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) return nums[0];
        
        int n = nums.size();
        if (n == 1) return (k % 2) ? -1 : nums[0];
        if (k == 1) return nums[1];
        
        int maxElement = *max_element(nums.begin(), nums.begin() + min(k - 1, n));
        
        return (k < n) ? max(nums[k], maxElement) : maxElement;
    }
};