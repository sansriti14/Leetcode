class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int min_chars = m;
        int i = 0, j = 0;
        while(i < n && j < m) {
            while(i < n && s[i] != t[j]) i++;
            if(i == n) return min_chars;
            
            else {
                --min_chars;
                i++;
                j++;
            }
        }
        
        return min_chars;
    }
};