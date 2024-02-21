class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL") != string::npos) return false;
        
        int absent = 0;
        for(auto ch: s) {
            if(ch == 'A') absent++;
            if(absent >= 2) return false;
        }
        
        return true;
    }
};