class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto word: strs) {
            string sorted = word;
            sort(begin(sorted), end(sorted));
            mp[sorted].push_back(word);
        }
        
        vector<vector<string>> ans;
        for(auto it: mp) { 
            ans.push_back(it.second);
        }
        
        return ans;
    }
};