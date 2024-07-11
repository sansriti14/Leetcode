class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        
        string ans = "";
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                int start = st.top() + 1;
                int end = i;

                reverse(begin(s) + start, begin(s) + end);
                st.pop();
            }
            
            else if (s[i] == '(') {
                st.push(i);
            }
        }

        for (auto &ch : s) {
            if (ch != '(' && ch != ')') {
                ans += ch;
            }
        }

        return ans;
    }
};