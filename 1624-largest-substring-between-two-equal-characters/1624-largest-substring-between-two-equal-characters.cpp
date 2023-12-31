class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> indices1(26, -1);
        vector<int> indices2(26, -1);
        int longest_substring = -1;

        for (int i = 0; i < s.size(); ++i) {
            int character = s[i] - 'a';

            if (indices1[character] == -1) {
                indices1[character] = i;
            } else {
                indices2[character] = i;
                longest_substring = max(longest_substring, indices2[character] - indices1[character] - 1);
            }
        }

        return longest_substring;
    }
};