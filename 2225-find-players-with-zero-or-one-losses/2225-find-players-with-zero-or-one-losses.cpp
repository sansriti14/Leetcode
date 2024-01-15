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
        
        vector<int> notLost, lostOnce;
        for(auto it: losers) {
            if(it.second == 0) notLost.push_back(it.first);
            if(it.second == 1) lostOnce.push_back(it.first); 
        }
        
        sort(notLost.begin(), notLost.end());
        sort(lostOnce.begin(), lostOnce.end());
        
        return {notLost, lostOnce};
    }
};