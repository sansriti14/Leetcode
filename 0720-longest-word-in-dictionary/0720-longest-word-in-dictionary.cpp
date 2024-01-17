class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(begin(words), end(words));
        unordered_set<string> dictionary(begin(words), end(words));
        
        int n = words.size();
        string longest_word = "";
        for(int index = n - 1; index >= 0; index--) {
            string word = words[index];
            
            string curr_word = "";
            for(int i = 0; i < word.size(); i++) {        
                if(dictionary.find(curr_word + word[i]) != dictionary.end()) {
                    curr_word += word[i];
                }
                
                else break;
                
                if(curr_word.size() >= longest_word.size()) {
                    longest_word = curr_word;
                }
            }
        }
        
        return longest_word;
    }
};