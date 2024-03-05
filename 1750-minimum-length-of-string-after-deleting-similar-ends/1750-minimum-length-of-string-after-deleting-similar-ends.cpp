class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n == 1 || s[0] != s[n - 1]) return n;
        
        int low = 0, high = n - 1;
        while(low < high) {
            if(s[low] != s[high]) break;
            
            char ch = s[low];
            while(low <= high && s[low] == ch) low++;
            
            while(low <= high && s[high] == ch) high--;
        }
        
        return high - low + 1;
    }
};