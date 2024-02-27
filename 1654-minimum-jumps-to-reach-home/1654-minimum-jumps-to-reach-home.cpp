class Solution {
private:
    int findMinJumps(int index, int canGoBackward, int a, int b, int x, unordered_set<int>& notAllowed, vector<vector<int>>& dp) {
        if(index == x) return 0;
        if(index < 0 || notAllowed.find(index) != notAllowed.end() || index > 6000) return 1e9;
        
        if(dp[index][canGoBackward] != -1) return dp[index][canGoBackward];
        
        dp[index][canGoBackward] = 1 + findMinJumps(index + a, 1, a, b, x, notAllowed, dp);
        if(canGoBackward) {
            dp[index][canGoBackward] = min(dp[index][canGoBackward], 1 + findMinJumps(index - b, 0, a, b, x, notAllowed, dp));
        }
        
        return dp[index][canGoBackward];
    }
    
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> notAllowed;
        for(int i = 0; i < forbidden.size(); i++) {
            notAllowed.insert(forbidden[i]);
        }
        
        vector<vector<int>> dp (7001, vector<int> (2, -1));
        
        int minJumps = findMinJumps(0, 0, a, b, x, notAllowed, dp);
        return (minJumps >= 1e9) ? -1 : minJumps;
    }
};