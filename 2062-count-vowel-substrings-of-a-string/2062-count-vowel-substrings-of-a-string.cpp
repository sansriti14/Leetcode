class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        if(n < 5) return 0;
        
        int num_substrings = 0;
        
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int i = 0, j = 0;
        while(i <= (n - 5)) {
            while(i <= (n - 5) && (vowels.find(word[i]) == vowels.end())) i++;
            j = i;
            
            unordered_set<char> st;
            while(j < n && (vowels.find(word[j]) != vowels.end())) {
                st.insert(word[j]);
                if(st.size() == 5) num_substrings++;
                j++;
            }
            
            i++;
        }
        
        return num_substrings;
    }
};