class Solution {
private:
    int findMinPathSum(int curr_row, int curr_col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(curr_row == m-1 && curr_col == n-1) return grid[m-1][n-1];
        if(curr_row >= m || curr_col >= n) return 1e9;
        
        if(dp[curr_row][curr_col] != -1) return dp[curr_row][curr_col];
        
        int down = grid[curr_row][curr_col], right = grid[curr_row][curr_col];
        down += findMinPathSum(curr_row + 1, curr_col, m, n, grid, dp);
        right += findMinPathSum(curr_row, curr_col + 1, m, n, grid, dp);
        
        return dp[curr_row][curr_col] = min(down, right);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findMinPathSum(0, 0, m, n, grid, dp);
    }
};