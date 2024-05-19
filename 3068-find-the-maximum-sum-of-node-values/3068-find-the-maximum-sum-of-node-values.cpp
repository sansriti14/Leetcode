class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        long long min_extra = 1e6;
        int count = 0;

        for (auto it: nums) {
            if ((it ^ k) < it) {
                sum += it;
                min_extra = min(min_extra, (long long)(it - (it ^ k)));
            } 
            
            else {
                sum += (it ^ k);
                min_extra = min(min_extra, (long long)((it ^ k) - it));
                count++;
            }
        }

        return (count % 2) ? sum - min_extra : sum;
    }
};