class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        
        long long numSubarrays = 0;
        
        bool minFound = false, maxFound = false;
        int start = 0;
        int minIndex = 0, maxIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minFound = false;
                maxFound = false;
                start = i + 1;
            }
            
            if (nums[i] == minK) {
                minFound = true;
                minIndex = i;
            }
            
            if (nums[i] == maxK) {
                maxFound = true;
                maxIndex = i;
            }
            
            if (minFound && maxFound) {
                numSubarrays += (min(minIndex, maxIndex) - start + 1);
            }
        }
        
        return numSubarrays;
    }
};