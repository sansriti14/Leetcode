class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long patch = 0;
        int index = 0;
        int count = 0;
        
        while (patch < n) {
            if (index < nums.size() && patch >= nums[index] - 1) {
                patch += nums[index++];
            } 
            
            else {
                patch += (patch + 1);
                count++;
            }
        }

        return count;
    }
};