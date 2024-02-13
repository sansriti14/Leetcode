class Solution {
private:
    bool isPalindrome(string& word) {
        int n = word.length();
        int i = 0;
        while(i < n / 2) {
            if(word[i] != word[n - i - 1]) return false;
            i++;
        }
        
        return true;
    }
    
public:
    string firstPalindrome(vector<string>& words) {
        for(auto curr_word: words) {
            if(isPalindrome(curr_word)) return curr_word;
        }
        
        return "";
    }
};