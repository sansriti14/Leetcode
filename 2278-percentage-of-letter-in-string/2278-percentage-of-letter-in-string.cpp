class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int count = 0;
        for(auto ch: s) {
            if(ch == letter) count++;
        }
        
        return ((count * 100) / n);
    }
};