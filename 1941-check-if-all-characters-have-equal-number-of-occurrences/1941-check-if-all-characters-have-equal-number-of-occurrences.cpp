class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        
        int freq = -1;
        for(auto it: mp) {
            if(freq == -1) {
                freq = it.second;
            }
            
            else if(freq != it.second) return false;
        }
        
        return true;
    }
};