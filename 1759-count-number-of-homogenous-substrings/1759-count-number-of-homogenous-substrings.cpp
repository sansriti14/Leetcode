class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int mod = 1e9 + 7;
        
        long long count = 0;
        while(j < n) {
            while(s[j] == s[i] && j < n) j++;
            
            int length = j - i;
            count += (((long long)(length) * (length + 1))/2) % mod;
            
            i = j;
        }
        
        return (int) count;
    }
};