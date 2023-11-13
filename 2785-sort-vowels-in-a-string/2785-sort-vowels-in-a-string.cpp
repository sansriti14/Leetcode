class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
public:
    string sortVowels(string s) {
        vector<char> store_vowels;
        
        for(int i = 0; i < s.length(); i++) {
            if(isVowel(tolower(s[i]))) {
                store_vowels.push_back(s[i]);
            }
        }
        
        sort(store_vowels.begin(), store_vowels.end());
        int index = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isVowel(tolower(s[i]))) {
                s[i] = store_vowels[index++];
            }
        }
        
        return s;
    }
};