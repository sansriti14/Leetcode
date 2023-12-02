class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq (26, 0);
        
        for(auto ch: chars) freq[ch - 'a']++;
        
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            vector<int> temp = freq;
            bool flag = true;
            
            for(auto ch: words[i]) {
                temp[ch - 'a']--;
                if(temp[ch - 'a'] < 0) {
                    flag = false; 
                    break;
                }
            }
            
            if(flag) ans += words[i].size();
        }
        
        return ans;
    }
};