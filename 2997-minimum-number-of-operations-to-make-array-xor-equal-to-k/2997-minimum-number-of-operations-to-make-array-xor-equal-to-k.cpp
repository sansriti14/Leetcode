class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cur_xor = 0;
        for (auto it: nums) cur_xor ^= it;
        cur_xor ^= k;
        
        return __builtin_popcount(cur_xor);
    }
};