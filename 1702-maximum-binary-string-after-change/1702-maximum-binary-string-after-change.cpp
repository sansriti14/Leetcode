class Solution {
public:
    string maximumBinaryString(string binary) {
        string ans = "";
        int n = binary.length();
        int i = 0;
        while(i < n && binary[i] == '1') {
            ans += '1';
            i++;
        }
        
        int ones = 0, zeros = 0;
        for(; i < n; i++) {
            if(binary[i] == '0') zeros++;
            else ones++;
        }
        
        for(int j = 0; j < zeros - 1; j++) ans += '1';
        
        if(zeros > 0) ans += '0';
        
        for(int j = 0; j < ones; j++) ans += '1';
        
        return ans;
    }
};