class Solution {
private:
    int partition(vector<int>& jobDifficulty, int d, int index, vector<vector<int>>& dp) {
        int n = jobDifficulty.size();
        if(index == n && d == 0) return 0;
        if(index == n || d == 0) return 1e9;
        
        if(dp[index][d] != -1) return dp[index][d];
        
        int curr_max_difficulty = 0;
        int min_difficulty = 1e9;
        for(int i = index; i < n; i++) {
            curr_max_difficulty = max(curr_max_difficulty, jobDifficulty[i]);
            min_difficulty = min(min_difficulty, curr_max_difficulty + partition(jobDifficulty, d - 1, i+1, dp));
        }
        
        return dp[index][d] = min_difficulty;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if(n < d) return -1;
        if(n == d) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        
        return partition(jobDifficulty, d, 0, dp);
    }
};