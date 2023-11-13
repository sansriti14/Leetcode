class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> store_vowels;
        
        for(int i = 0; i < s.length(); i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                store_vowels.push_back(s[i]);
            }
        }
        
        sort(store_vowels.begin(), store_vowels.end());
        int index = 0;
        for(int i = 0; i < s.length(); i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                s[i] = store_vowels[index++];
            }
        }
        
        return s;
    }
};