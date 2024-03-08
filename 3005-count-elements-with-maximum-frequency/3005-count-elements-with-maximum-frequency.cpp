class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int max_freq = 0;
        for(auto it: nums) {
            max_freq = max(max_freq, ++mp[it]);
        }
        
        int total = 0;
        for(auto it: mp) {
            if(it.second == max_freq) {
                total += it.second;
            }
        }
        
        return total;
    }
};