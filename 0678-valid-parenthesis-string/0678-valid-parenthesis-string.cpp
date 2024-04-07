class Solution {
public:
    bool checkValidString(string s) {
        int unmatchedLeft = 0;  
        int maxRightNeeded = 0; 
        
        for (char ch : s) {
            if (ch == '(')
                unmatchedLeft++, maxRightNeeded++;
            if (ch == ')')
                maxRightNeeded--, unmatchedLeft = max(unmatchedLeft - 1, 0); 
            if (ch == '*')
                maxRightNeeded++, unmatchedLeft = max(unmatchedLeft - 1, 0);
            if (maxRightNeeded < 0) return false;
        }
        
        return (unmatchedLeft == 0);
    }
};