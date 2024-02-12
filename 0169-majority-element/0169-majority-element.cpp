class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        return (nums[n / 2]);
    }
};