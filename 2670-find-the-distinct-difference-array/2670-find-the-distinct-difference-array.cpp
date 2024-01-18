class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> distinct_in_prefix (n), distinct_in_suffix (n + 1, 0);
        unordered_set<int> st_prefix, st_suffix;
        
        int distinct_prefix = 0, distinct_suffix = 0;
        for(int i = 0; i < n; i++) {
            if(st_prefix.find(nums[i]) == st_prefix.end()) {
                ++distinct_prefix;
                st_prefix.insert(nums[i]);
            }
            
            if(st_suffix.find(nums[n - i - 1]) == st_suffix.end()) {
                ++distinct_suffix;
                st_suffix.insert(nums[n - i - 1]);
            }
            
            distinct_in_prefix[i] = distinct_prefix;
            distinct_in_suffix[n - i -1] = distinct_suffix;
        }
        
        vector<int> distinct_diff (n);
        for(int i = 0; i < n; i++) { 
            distinct_diff[i] = distinct_in_prefix[i] - distinct_in_suffix[i + 1];
        }
        
        return distinct_diff;
    }
};