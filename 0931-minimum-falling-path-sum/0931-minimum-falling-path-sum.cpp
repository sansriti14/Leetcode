class Solution {
private:
    int findMinPathSum(int curr_row, int curr_col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(curr_row == n-1  && curr_col >= 0 && curr_col < n) return matrix[curr_row][curr_col];
        if(curr_row == n || curr_col < 0 || curr_col == n) return 1e9;
        
        if(dp[curr_row][curr_col] != INT_MAX) return dp[curr_row][curr_col];
        
        int down = matrix[curr_row][curr_col] + findMinPathSum(curr_row + 1, curr_col, n, matrix, dp);
        int diagonal_left = matrix[curr_row][curr_col] + findMinPathSum(curr_row + 1, curr_col - 1, n, matrix, dp);
        int diagonal_right = matrix[curr_row][curr_col] + findMinPathSum(curr_row + 1, curr_col + 1, n, matrix, dp);
        
        return dp[curr_row][curr_col] = min(down, min(diagonal_left, diagonal_right));
        
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int min_path_sum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int col = 0; col < n; col++) {
            min_path_sum = min(min_path_sum, findMinPathSum(0, col, n, matrix, dp));
        }
        
        return min_path_sum;
    }
};