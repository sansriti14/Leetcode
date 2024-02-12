class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j) {
            if(isalnum(s[i]) && isalnum(s[j])) {
                if(tolower(s[i]) != tolower(s[j])) return false;
                else {
                    i++;
                    j--;
                }
            }
            
            else if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
        }
        
        return true;
    }
};