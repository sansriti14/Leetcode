class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int index = n;
        unordered_map<char, pair<int, int>> mp;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(mp.find(ch) == mp.end()) {
                mp[ch].first = 1;
                mp[ch].second = i;
            }
            
            else mp[ch].first++;
        }
        
        for(auto it: mp) {
            if(it.second.first == 1) index = min(index, it.second.second);
        }
        
        return (index == n) ? -1 : index;
    }
};