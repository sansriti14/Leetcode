class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq1(26, INT_MAX);
        for (auto word : words) {
            vector<int> freq2(26, 0);
            
            for (auto ch : word) {
                freq2[ch - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                freq1[i] = min(freq1[i], freq2[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            while (freq1[i]-- > 0) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};