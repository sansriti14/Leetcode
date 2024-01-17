class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        
        unordered_set<int> freq;
        for(auto it: mp) {
            if(freq.find(it.second) != freq.end()) return false;
            freq.insert(it.second);
        }
        
        return true;
    }
};