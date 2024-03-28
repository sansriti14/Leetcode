class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        
        int maxLength = 0;
        while (j < n) {
            while (j < n && mp[nums[j]] + 1 <= k) ++mp[nums[j++]];
            maxLength = max(maxLength, j - i);
            
            --mp[nums[i++]];
        }
        
        return maxLength;
    }
};