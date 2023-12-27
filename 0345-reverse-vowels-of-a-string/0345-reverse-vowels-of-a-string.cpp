class Solution {
private:
    bool isVowel(char ch) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        return (vowels.find(ch) != vowels.end());
    }
    
public:
    string reverseVowels(string s) {
        vector<int> store_vowels;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i]))
                store_vowels.push_back(s[i]);
        }
        
        int index = 0;
        for(int i = n-1; i >= 0; i--) {
            if(isVowel(s[i]))
                s[i] = store_vowels[index++];
        }
        
        return s;
    }
};