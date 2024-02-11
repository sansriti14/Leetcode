class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        int max_length = 0;
        int i = 0;
        for(int j = 0; j < n; j++) {
            while(i < n && nums[j] - nums[i] > 2 * k) i++;
            max_length = max(max_length, j - i + 1);
        }
        
        return max_length;
    }
};