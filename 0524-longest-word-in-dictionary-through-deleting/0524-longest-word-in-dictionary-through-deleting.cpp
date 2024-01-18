class Solution {
private:
    bool isSubsequence(string& word, string& s) {
        int n = word.length();
        int m = s.length();
        
        if(n > m) return false;
        if(n == m) return word == s;
        
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(word[i] == s[j]) {
                i++;
            }
            
            j++;
        }
        
        return i == n;
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(begin(dictionary), end(dictionary));
        string longest_word = "";
        
        for(auto word: dictionary) {
            if(isSubsequence(word, s) && word.length() > longest_word.length()) {
                longest_word = word;
            }
        }
        
        return longest_word;
    }
};