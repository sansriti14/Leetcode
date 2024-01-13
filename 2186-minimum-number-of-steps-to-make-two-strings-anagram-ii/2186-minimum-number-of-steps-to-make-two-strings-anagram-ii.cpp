class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_freq(26, 0), t_freq(26, 0);
        
        for(char ch: s) {
            s_freq[ch - 'a']++;
        }
        
        for(char ch: t) {
            t_freq[ch - 'a']++;
        }
        
        int min_steps = 0;
        for (int i = 0; i < 26; i++) {
            min_steps += abs(s_freq[i] - t_freq[i]);
        }
        
        return min_steps;
    }
};