class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        int max_length = 0;
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && nums[j] - nums[i] > 2 * k) i++;
            max_length = max(max_length, j - i + 1);
            j++;
        }
        
        return max_length;
    }
};