class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = (n * (n + 1)) / 2;
        int actual_sum = accumulate(begin(nums), end(nums), 0);
        
        return expected_sum - actual_sum;
    }
};