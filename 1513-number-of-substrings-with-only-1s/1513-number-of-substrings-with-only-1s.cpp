class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int num_substrings = 0;
        int mod = 1e9 + 7;
        
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(s[j] == '1') {
                num_substrings = (num_substrings + j - i + 1) % mod;
            }
            
            else i = j + 1;
            j++;
            
        }
        
        return num_substrings;
    }
};