class Solution {
private:
    bool checkPalindrome(string& str) {
        int n = str.length();
        int i = 0;
        while(i < n / 2) {
            if(str[i] != str[n - i - 1]) return false;
            i++;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto ch: s) {
            if(isalnum(ch)) {
                str += tolower(ch);
            }
        }
        
        return checkPalindrome(str);
    }
};