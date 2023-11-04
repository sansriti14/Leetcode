class Solution {
private:
    int findMinPathSum(int curr_row, int curr_col, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(curr_row == n-1) return grid[curr_row][curr_col];
        
        if(dp[curr_row][curr_col] != 1e9) return dp[curr_row][curr_col];
        
        int min_sum = 1e9;
        for(int col = 0; col < n; col++) {
            if(col == curr_col) continue;
            
            min_sum = min(min_sum, grid[curr_row][curr_col] + findMinPathSum(curr_row + 1, col, n, grid, dp));
        }
        return dp[curr_row][curr_col] = min_sum;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int min_path_sum = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int col = 0; col < n; col++) {
            min_path_sum = min(min_path_sum, findMinPathSum(0, col, n, grid, dp));
        }
        
        return min_path_sum;
    }
};