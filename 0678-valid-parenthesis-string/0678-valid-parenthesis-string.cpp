class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        
        stack<char> st;
        int countAsterisk = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') countAsterisk++;
            
            else if (s[i] == '(') st.push(s[i]);
            
            else if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else if (countAsterisk > 0) countAsterisk--;
                else return false;
            }
        }
        
        while (!st.empty()) st.pop();
        countAsterisk = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') countAsterisk++;
            
            else if (s[i] == ')') st.push(s[i]);
            
            else if (s[i] == '(') {
                if (!st.empty()) st.pop();
                else if (countAsterisk > 0) countAsterisk--;
                else return false;
            }
        }
        
        return true;
    }
};