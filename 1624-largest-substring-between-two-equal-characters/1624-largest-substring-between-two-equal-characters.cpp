class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int longest_substring = -1;
        
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (s[left] == s[right]) {
                    longest_substring = max(longest_substring, right - left - 1);
                }
            }
        }
        
        return longest_substring;
    }
};