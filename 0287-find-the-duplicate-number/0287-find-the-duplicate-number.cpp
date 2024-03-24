class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto num: nums) {
            int index = abs(num);
            if(nums[index] < 0) return index;
            
            nums[index] = -nums[index];
        }
        
        return nums.size();
    }
};