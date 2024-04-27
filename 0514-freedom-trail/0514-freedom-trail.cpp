class Solution {
private:
    int findSteps(int p1, int p2, string &ring, string &key, vector<int> pos[26], vector<vector<int>>& dp) {
        int n = ring.size();
        
        if (p2 == key.size()) return 0;
        if (dp[p1][p2]) return dp[p1][p2];
        
        int minSteps = INT_MAX;
        for (auto it: pos[key[p2] - 'a']) {
            int dist = abs(p1 - it);
            minSteps = min(minSteps, min(dist, n - dist) + findSteps(it, p2 + 1, ring, key, pos, dp));    
        }
        
        return dp[p1][p2] = minSteps + 1;
    }
    
public:
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        int n = ring.size();
        for (int i = 0; i < n; i++){
           pos[ring[i] - 'a'].push_back(i); 
        } 
        
        vector<vector<int>> dp (n, vector<int> (key.size()));
        return findSteps(0, 0, ring, key, pos, dp);    
    }
};