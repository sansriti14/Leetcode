class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n & 1) return false;
        
        int unlocked = 0, opened = 0, closed = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == '(') opened++;
            else if (s[i] == ')') closed++;
            
            int unpaired = closed - opened;
            if (unpaired > unlocked)
                return false;
        }
          
        unlocked = 0, opened = 0, closed = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == '(') opened++;
            else if (s[i] == ')') closed++;
            
            int unpaired = opened - closed;
            if (unpaired > unlocked)
                return false;
        }
          
        return true;
    }
};