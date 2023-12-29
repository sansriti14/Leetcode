class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int size = nums.size();
        vector<int> prevMax(size, 0), nextMax(size, 0);
        
        int maxVal = nums[0];
        for (int i = 1; i < size; i++) {
            prevMax[i] = maxVal;
            maxVal = max(maxVal, nums[i]);
        }
        
        maxVal = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            nextMax[i] = maxVal;
            maxVal = max(maxVal, nums[i]);
        }
        
        long long maxTripletValue = 0;
        for (int i = 0; i < size - 1; i++) {
            long long val = (prevMax[i] - (1LL * nums[i])) * (1LL * nextMax[i]);
            if (maxTripletValue < val) {
                maxTripletValue = val;
            }
        }
        
        return maxTripletValue;
    }
};
