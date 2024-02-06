class Solution {
private:
    bool areAnagrams(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        
        vector<int> freq (26, 0);
        for(int i = 0; i < word1.length(); i++) {
            freq[word1[i] - 'a']++;
            freq[word2[i] - 'a']--;
        }
        
        for(auto it: freq) {
            if(it != 0) return false;
        }
        
        return true;
    }
    
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1; i < words.size(); ) {
            if(areAnagrams(words[i - 1], words[i])) {
                words.erase(words.begin() + i);
            }
            
            else i++;
        }
        
        return words;
    }
};