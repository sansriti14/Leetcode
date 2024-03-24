class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = ((long long)(n * (n + 1))) / 2;
        
        int actualSum = accumulate(begin(nums), end(nums), 0);
        
        return expectedSum - actualSum;
    }
};