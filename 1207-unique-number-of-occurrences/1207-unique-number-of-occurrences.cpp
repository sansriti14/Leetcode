class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        
        unordered_set<int> freq;
        for(auto it: mp) {
            freq.insert(it.second);
        }
        
        return (freq.size() == mp.size());
    }
};