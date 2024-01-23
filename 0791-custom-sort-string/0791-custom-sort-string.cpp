class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (auto ch: s) mp[ch]++;
        
        string str = ""; 
        for(auto ch: order) {
            if(mp.find(ch) != mp.end() && mp[ch] > 0) {
                while(mp[ch]--) str += ch;
            }
        }
        
        for(auto it: mp) {
            if(it.second > 0) {
                while(it.second--) str += it.first;
            }
        }
        
        return str;
    }
};