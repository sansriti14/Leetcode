class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if(n < d) return -1;
        if(n == d) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        
        vector<vector<int>> dp(d, vector<int>(n, 0));
        dp[0][0] = jobDifficulty[0];
        for(int j = 1; j < n; j++) {
            dp[0][j] = max(dp[0][j-1], jobDifficulty[j]);
        }

        for(int i = 1; i < d; i++) {
            for(int length = i; length < n; length++) {
                int curr_max_difficulty = jobDifficulty[length];
                dp[i][length] = 1e9;
                
                for(int schedule = length; schedule >= i; schedule--) {
                    curr_max_difficulty = max(curr_max_difficulty, jobDifficulty[schedule]);
                    dp[i][length] = min(dp[i][length], curr_max_difficulty + dp[i-1][schedule-1]);
                }
            }
        }
        
        return dp[d-1][n-1];
    }
};