class Solution {
public:
    int countHillValley(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); 
        int count = 0;
        
        for(int i = 1; i < nums.size() -1; ++i) {
            count += (nums[i-1] < nums[i] && nums[i] > nums[i+1]) || (nums[i-1] > nums[i] && nums[i] < nums[i+1]);
        }
        
        return count;
    }
};