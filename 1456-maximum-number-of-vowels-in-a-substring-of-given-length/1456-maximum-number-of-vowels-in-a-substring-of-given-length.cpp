class Solution {
private:
    bool isVowel(char ch) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        return (st.find(ch) != st.end());
    }
    
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        
        int currVowels = 0;
        
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) currVowels++;
        }
        
        int maxVowels = currVowels;
        int i = 0, j = k - 1;
        while (j < n) {
            if(isVowel(s[i++])) currVowels--;
            
            if(isVowel(s[++j])) currVowels++;
            
            maxVowels = max(maxVowels, currVowels);
        }
        
        return maxVowels;
    }
};
