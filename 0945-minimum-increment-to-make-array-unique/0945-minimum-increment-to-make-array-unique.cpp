class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int minMoves = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                minMoves += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return minMoves;
    }
};