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
        
        for (int curr_distinct = 1; curr_distinct <= total_distinct; curr_distinct++) {
            int start = 0, end = 0;
            int currCount = 0, countExactlyK = 0;
            freq.clear();
            
            while (end < n) {
                if (currCount <= curr_distinct) {
                    if (++freq[s[end]] == k) countExactlyK++;
                    if (freq[s[end]] == 1) currCount++;
                    end++;
                }
                
                else {
                    if (freq[s[start]] == k) countExactlyK--;
                    if (--freq[s[start]] == 0) currCount--;
                    start++;
                }
                
                if (currCount == curr_distinct && countExactlyK == curr_distinct) {
                    maxLength = max(maxLength, end - start);
                }
            }
        }
        
        return maxLength;
    }
};
