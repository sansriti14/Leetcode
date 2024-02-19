class Solution {
public:
        int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
            
        long long K = k;
        int i = 0, j = 0;
        for (; j < nums.size(); j++) {
            K += nums[j];
            if (K < (long long)nums[j] * (j - i + 1))
                K -= nums[i++];
        }
        return j - i;
    }
};