class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n < k) return 0;
         
        unordered_map<char, int> freq;
        int total_distinct = 0;
        for(auto ch: s) {
            if (++freq[ch] == 1) total_distinct++;
        }

        int maxLength = 0;
        
        for (int i = 1; i <= total_distinct; i++) {
            int start = 0, end = 0;
            int currCount = 0, countExactlyK = 0;
            freq.clear();
            
            while (end < n) {
                if (currCount <= i) {
                    if (++freq[s[end]] == k) countExactlyK++;
                    if (freq[s[end]] == 1) currCount++;
                    end++;
                }
                
                else {
                    if (freq[s[start]] == k) countExactlyK--;
                    if (--freq[s[start]] == 0) currCount--;
                    start++;
                }
                
                if (currCount == i && countExactlyK == i) {
                    maxLength = max(maxLength, end - start);
                }
            }
        }
        
        return maxLength;
    }
};
