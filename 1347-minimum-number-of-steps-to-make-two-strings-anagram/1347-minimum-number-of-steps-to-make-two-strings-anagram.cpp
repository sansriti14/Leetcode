class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq (26, 0);
        for(auto ch: s) {
            freq[ch - 'a']++;
        }
        
        for(auto ch: t) {
            freq[ch - 'a']--;
        }
        
        int count = 0;
        for(auto it: freq) {
            if(it > 0)
                count += it;
        }
        
        return count;
    }
};