class Solution {
public:
    int maxDepth(string s) {
        int nestingDepth = 0;
        int count = 0;
        
        for (char& ch: s) {
            if (ch == '(') {
                nestingDepth = max(nestingDepth, ++count);
            } 
            
            else if (ch == ')') {
                count--;
            }
        }
        
        return nestingDepth;
    }
};