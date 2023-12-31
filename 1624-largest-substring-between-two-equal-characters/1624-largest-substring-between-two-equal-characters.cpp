class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstIndex;
        int max_diff = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                max_diff = max(max_diff, i - firstIndex[s[i]]);
            } else {
                firstIndex[s[i]] = i;
            }
        }

        return (max_diff == -1) ? -1 : max_diff - 1;
    }
};