class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        
        stack<char> st;
        int countAsterisk = 0;
        
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '*':
                    countAsterisk++;
                    break;
                
                case '(':
                    st.push(s[i]);
                    break;
                
                case ')':
                    if (!st.empty()) st.pop();
                    else if (countAsterisk > 0) countAsterisk--;
                    else return false;  
                    break;
            }
        }
        
        while (!st.empty()) st.pop();
        countAsterisk = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            switch (s[i]) {
                case '*':
                    countAsterisk++;
                    break;
                
                case ')':
                    st.push(s[i]);
                    break;
                
                case '(':
                    if (!st.empty()) st.pop();
                    else if (countAsterisk > 0) countAsterisk--;
                    else return false;  
                    break;
            }
        }
        
        return true;
    }
};