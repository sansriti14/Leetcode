class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int, char>> freq (26, {0, 'A'});
        for(auto ch: word) {
            freq[ch - 'a'].first++;
            freq[ch - 'a'].second = ch;
        }
        
        sort(begin(freq), end(freq), greater<pair<int, char>>());
        
        int min_pushes = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i].first == 0) break;
            
            if(0 <= i && i <= 7) min_pushes += (freq[i].first);
            else if(8 <= i && i <= 15) min_pushes += (2 * freq[i].first);
            else if(16 <= i && i <= 23) min_pushes += (3 * freq[i].first);
            else min_pushes += (4 * freq[i].first);
        }
        
        return min_pushes;
    }
};