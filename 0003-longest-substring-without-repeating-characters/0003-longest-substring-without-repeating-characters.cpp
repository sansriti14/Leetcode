class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        int i = 0, j = 0;
        int max_length = 0;
        while(j < n) {
            if(mp.find(s[j]) != mp.end()) {
                i = max(mp[s[j]] + 1, i);
            }
            
            max_length = max(max_length, j - i + 1); 
            mp[s[j]] = j;
            j++;
        }
        
        return max_length;
    }
};