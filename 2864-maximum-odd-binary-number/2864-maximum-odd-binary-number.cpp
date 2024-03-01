class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int num_ones = 0;
        for(auto ch: s) {
            if(ch == '1') num_ones++;
        }
        
        int num_zeros = n - num_ones;
        string maxOddNumber = "";
        while(--num_ones) maxOddNumber += '1';
        while(num_zeros--) maxOddNumber += '0';
        
        maxOddNumber += '1';
        
        return maxOddNumber;
    }
};