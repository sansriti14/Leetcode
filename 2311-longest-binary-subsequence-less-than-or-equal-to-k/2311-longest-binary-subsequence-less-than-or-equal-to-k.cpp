class Solution {
public:
    int longestSubsequence(string s, int k) {
        int max_length = 0;
        int base = 1;
        int number = 0;
        int i;
        
        for(i = s.length() - 1; i >= 0; i--) {
            if(number + base > k) break;
            
            if(s[i] == '1') number += base;
            
            base *= 2;
            max_length++;
        }
        
        while(i >= 0) {
            if(s[i] == '0') max_length++;
            i--;
        }
        
        return max_length;
    }
};