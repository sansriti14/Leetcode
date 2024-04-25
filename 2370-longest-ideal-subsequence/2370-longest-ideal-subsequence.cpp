class Solution {
private:
    int findLIS(string& s, int prev, int curr_index, int k, vector<vector<int>>& dp) {
        if (curr_index >= s.length()) return 0;
        if (dp[curr_index][prev] != -1) return dp[curr_index][prev];
        
        int not_take = 0, take = 0;
        not_take = findLIS(s, prev, curr_index + 1, k, dp);
        
        if (prev == 0 || abs(s[curr_index] - prev) <= k) {
            take = max(not_take, 1 + findLIS(s, s[curr_index], curr_index + 1, k, dp));
        }
        
        return dp[curr_index][prev] = max(take, not_take);
    }
    
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp (n + 1, vector<int> (150, -1));
        return findLIS(s, 0, 0, k, dp);
    }
};