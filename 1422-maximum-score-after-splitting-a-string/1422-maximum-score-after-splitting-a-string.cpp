class Solution {
public:
    int maxScore(string s) {
        int total_ones = 0;
        for(int i = 0; i < s.length(); i++) {
            total_ones += (s[i] - '0');  
        }
        
        int count_zeros = 0, max_score = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '0') count_zeros++;
            else total_ones--;
            
            max_score = max(max_score, (count_zeros + total_ones));
        }
        
        return max_score;
    }
};