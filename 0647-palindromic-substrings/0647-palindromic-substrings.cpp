class Solution {
private:
    int solve(string& str, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 1;
        if(str[i] != str[j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = solve(str, i + 1, j - 1, dp);
    }
    
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += solve(s, i, j, dp);
            }
        }
        return count;
    }
};