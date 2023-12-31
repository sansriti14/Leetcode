class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mp;
        
        for(int i = 0; i < s.size(); i++) {    
            mp[s[i]].push_back(i);
        }
        
        int max_diff = -1;
        for(auto it: mp) {
            vector<int> indices = it.second;
            sort(indices.begin(), indices.end());
            int n = indices.size();
            if(n > 1)
                max_diff = max(max_diff, indices[n-1] - indices[0]); 
        }
        
        return (max_diff == -1) ? -1 : max_diff - 1;
    }
};