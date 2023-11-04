class Solution {
private:
    int countUniquePaths(int curr_row, int curr_col, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(curr_row == m-1 && curr_col == n-1) return 1;
        if(curr_row >= m || curr_col >= n) return 0;
        
        if(dp[curr_row][curr_col] != -1) return dp[curr_row][curr_col];
        
        int up = 0, down = 0;
        if(curr_row + 1 < m && obstacleGrid[curr_row + 1][curr_col] == 0)
            up = countUniquePaths(curr_row + 1, curr_col, m, n, obstacleGrid, dp);
        if(curr_col + 1 < n && obstacleGrid[curr_row][curr_col + 1] == 0)
            down = countUniquePaths(curr_row, curr_col + 1, m, n, obstacleGrid, dp);
        
        
        return dp[curr_row][curr_col] = up + down;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countUniquePaths(0, 0, m, n, obstacleGrid, dp);
    }
};