class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            string word = q.front().first;
            int seq_length = q.front().second;
            q.pop();
            
            if(word == endWord) return seq_length;
            
            for(int i = 0; i < word.size(); i++) {
                char original_char = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(word_list.find(word) != word_list.end()) {
                        q.push({word, seq_length + 1});
                        word_list.erase(word);
                    }
                }
                word[i] = original_char;
            }
        }
        
        return 0;
    }
};