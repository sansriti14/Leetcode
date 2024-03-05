class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if(n < m) return -1;

        int first_index = -1;
        for(int i = 0; i <= n - m; i++) {
            if(haystack[i] != needle[0]) continue;
            
            if(haystack.substr(i, m) == needle) {
                first_index = i;
                break;
            }
        }
        
        return first_index;
    }
};