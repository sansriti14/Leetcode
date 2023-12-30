class Solution {
public:
    int numWays(string s) {
        int n = s.length();
        
        int count_ones = 0;
        for(auto ch: s) {
            count_ones += (ch - '0');
        }
        
        int mod = 1e9 + 7;
        if(count_ones == 0) return (int) (((long long)(n - 1) * (n - 2) / 2) % mod);
        if((count_ones % 3) != 0) return 0;
        
        long long firstZeros = 0, secondZeros = 0, avg = count_ones / 3, prefixOnes = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '1') prefixOnes++;
            else {
                if (prefixOnes == avg) firstZeros++; 
                else if (prefixOnes == avg * 2) secondZeros++; 
            }
        }
        return (int) (++firstZeros * ++secondZeros % mod); 
    }
};