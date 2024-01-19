class Solution {
private:
    int findMinSum(int curr_row, int curr_col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        
        if(curr_row == n - 1 && curr_col >= 0 && curr_col < n) return matrix[curr_row][curr_col];
        if(curr_row == n || curr_col < 0 || curr_col == n) return 1e9;
        
        if(dp[curr_row][curr_col] != 1e9) return dp[curr_row][curr_col];
        
        int down = matrix[curr_row][curr_col], diagonal_left = matrix[curr_row][curr_col], diagonal_right = matrix[curr_row][curr_col];
        
        down += findMinSum(curr_row + 1, curr_col, matrix, dp);
        diagonal_left += findMinSum(curr_row + 1, curr_col - 1, matrix, dp);
        diagonal_right += findMinSum(curr_row + 1, curr_col + 1, matrix, dp);
        
        return dp[curr_row][curr_col] = min(down, min(diagonal_left, diagonal_right));
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n, 1e9));
        
        int min_sum = 1e9;
        for(int col = 0; col < n; col++) {
            min_sum = min(min_sum, findMinSum(0, col, matrix, dp));
        }
        
        return min_sum;
    }
};