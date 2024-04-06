class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') open--;
            
            if (open < 0) {
                s[i] = '*';
                open++;
            }
        }
        
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (isalpha(s[i]) || s[i] == ')') ans += s[i];
            else if (s[i] == '*') continue;
            else if (s[i] == '(') {
                if (open > 0) open--;
                else ans += s[i];
            } 
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};