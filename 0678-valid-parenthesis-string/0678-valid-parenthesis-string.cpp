class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        
        int countOpened = 0;
        int countAsterisk = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') countAsterisk++;
            
            else if (s[i] == '(') countOpened++;
            
            else if (s[i] == ')') {
                if (countOpened > 0) countOpened--;
                else if (countAsterisk > 0) countAsterisk--;
                else return false;
            }
        }
        
        int countClosed = 0;
        countAsterisk = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') countAsterisk++;
            
            else if (s[i] == ')') countClosed++;
            
            else if (s[i] == '(') {
                if (countClosed > 0) countClosed--;
                else if (countAsterisk > 0) countAsterisk--;
                else return false;
            }
        }
        
        return true;
    }
};