class Solution {
private:
    string sortString(string& str) {
        vector<int> freq (26, 0);
        for (auto ch: str) freq[ch - 'a']++;
        
        string sorted = "";
        for (int i = 0; i < 26; ) {
            if (freq[i] == 0) i++;
            
            else {
                sorted += (i + 'a');
                freq[i]--;
            }
        }
        
        return sorted;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto word: strs) {
            string sorted = sortString(word);
            mp[sorted].push_back(word);
        }
        
        vector<vector<string>> ans;
        for(auto& it: mp) { 
            ans.push_back(it.second);
        }
        
        return ans;
    }
};