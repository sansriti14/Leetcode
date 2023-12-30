class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> freq;
        for(int i = 0; i < n; i++) {
            for(auto ch: words[i]) {
                freq[ch - 'a']++;
            }
        }
        
        for(auto it: freq) {
            if(it.second % n != 0)
                return false;
        }
        
        return true;
    }
};