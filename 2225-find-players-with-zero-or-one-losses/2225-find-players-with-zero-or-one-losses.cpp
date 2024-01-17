class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losers;
        for(int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            if(losers.find(winner) == losers.end()) {
                losers[winner] = 0;
            }
            
            losers[loser]++;
        }
        
        vector<vector<int>> ans(2);
        for(auto it: losers) {
            if(it.second == 0) ans[0].push_back(it.first);
            if(it.second == 1) ans[1].push_back(it.first); 
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};