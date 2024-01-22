class Solution {
private:
    int atMostK(string& word, int k) {
        int n = word.size();
        
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp;
        
        int num_substrings = 0;
        int i = 0;
        
        for(int j = 0; j < n; j++) {
            if (vowels.find(word[j]) == vowels.end()) {
                i = j + 1;
                mp.clear();
                continue;
            }
            
            mp[word[j]]++;
            
            while(mp.size() > k) {
                if(--mp[word[i]] == 0) mp.erase(word[i]);
                i++;
            }
            
            num_substrings += (j - i + 1);
        }
        
        return num_substrings;
    }

public:
    int countVowelSubstrings(string word) {
        return atMostK(word, 5) - atMostK(word, 4);
    }
};