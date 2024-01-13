class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq (26, 0);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        int count = 0;
        for(auto it: freq) {
            if(it > 0)
                count += it;
        }
        
        return count;
    }
};