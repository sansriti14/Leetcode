class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if (n == 1) return s;
        
        string good_str = "";
        
        int i = 0, j = 1;
        for (int i = 0; i < n; i++) {
            good_str += s[i];
            while (!good_str.empty() && abs(good_str.back() - s[i + 1]) == 32) {
                good_str.pop_back();
                i++;
            }
        }
        
        return good_str;
    }
};