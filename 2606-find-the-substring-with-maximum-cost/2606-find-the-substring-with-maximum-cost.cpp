class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> letters (26);
        for(int i = 0; i < 26; i++) {
            letters[i] = i+1;
        }
        
        for(int i = 0; i < chars.size(); i++) {
            letters[chars[i] - 'a'] = vals[i];
        }
        
        int n = s.size();
        vector<int> costs(n);
        for(int i = 0; i < s.size(); i++){
            costs[i] = letters[s[i] - 'a'];
        }
        
        int max_cost = 0, curr_cost = 0;
        for(int i = 0; i < n; i++){
            curr_cost += costs[i];
            if(curr_cost < 0) curr_cost = 0;
            max_cost = max(max_cost, curr_cost);
        }
        return max_cost;
        
    }
};