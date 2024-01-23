class Solution {
private:
    int wordCount(vector<string>& message) {
        int word_count = 0;
        
        for(auto msg: message) {
            int n = msg.length();
            int j = 0;
            while(j < n) {
                while(j < n && msg[j] != ' ') j++;
                word_count++;
                j++;
            }
        }
        
        return word_count;
    }
    
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        map<string, vector<string>> mp;
        
        for(int i = 0; i < n; i++) {
            mp[senders[i]].push_back(messages[i]);
        }
        
        int max_word_count = 0;
        string max_wc_sender = "";
        for(auto sender: mp) {
            vector<string> message = sender.second;
            int curr_word_count = wordCount(message);
            
            if(curr_word_count >= max_word_count) {
                max_word_count = curr_word_count;
                max_wc_sender = sender.first;
            }
        }
        
        return max_wc_sender;
    }
};