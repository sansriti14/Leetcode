class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        bool zeroPresent = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) zeroPresent = true;
            int index = abs(nums[i]) - 1;
            if(index < 0) continue;
            nums[index] = -nums[index];
        }
        
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i + 1;
            if(nums[i] == 0) index = i;
        }
        
        return (zeroPresent == true) ? index + 1 : 0;
    }
};