class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;
        
        int pairs_removed = 0;
        for(auto it: mp) {
            pairs_removed += (it.second / 2);
        }
        
        int leftovers = (pairs_removed == 0) ? n : n - 2 * pairs_removed;
        return {pairs_removed, leftovers};
    }
};