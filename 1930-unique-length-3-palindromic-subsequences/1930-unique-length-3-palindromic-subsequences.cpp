class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> occurence(26, {-1, -1});
        
        for(int i = 0; i < s.length(); i++) {
            if(occurence[s[i] - 'a'].first == -1) occurence[s[i] - 'a'].first = i;
            else occurence[s[i] - 'a'].second = i;
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(occurence[i].second != -1) {
                unordered_set<char> unique_chars;
                for(int j = occurence[i].first+1; j < occurence[i].second; j++) {
                    unique_chars.insert(s[j] - 'a');
                }
                
                count += unique_chars.size();
            }
        }
        
        return count;
    }
};