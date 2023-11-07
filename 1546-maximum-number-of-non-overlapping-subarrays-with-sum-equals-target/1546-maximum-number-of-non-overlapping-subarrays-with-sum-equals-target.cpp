class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> prefixSum;
        int count = 0;
        int curr_sum = 0, right = -2;
        prefixSum[0] = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            
            if(prefixSum.count(curr_sum - target) && prefixSum[curr_sum - target] >= right) {
                count++;
                right = i;
            }
            
            prefixSum[curr_sum] = i;
        }
        
        return count;
    }
};