class Solution {
private:
    bool isLetter(char ch) {
        return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
    }
    
public:
    string reverseOnlyLetters(string s) {
        vector<char> letters;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(isLetter(s[i])) {
                letters.push_back(s[i]);
            }
        }
        
        int index = 0;
        for(int i = n-1; i >=0; i--) {
            if(isLetter(s[i]))
                s[i] = letters[index++];
        }
        
        return s;
    }
};