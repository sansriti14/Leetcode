class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long min_chars = 0;
        long long count0 = 0, count1 = 0;
        
        for(auto ch: text) {            
            if(ch == pattern[1]) {
                min_chars += count0;
                count1++;
            }
            
            if(ch == pattern[0]) {
                count0++;
            }
        }
        
        return min_chars + max(count0, count1);
    }
};