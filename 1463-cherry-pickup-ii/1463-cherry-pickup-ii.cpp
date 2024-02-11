class Solution {
private:
    int findMaxCherries(int row, int col1, int col2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(row == n - 1) return (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        int max_cherries = -1e9;

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int cherries = ((col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2]);
                if(row + 1 < n && col1 + i >= 0 && col1 + i < m && col2 + j >= 0 && col2 + j < m) {
                    cherries += findMaxCherries(row + 1, col1 + i, col2 + j, n, m, grid, dp);
                    max_cherries = max(max_cherries, cherries);  
                }
            }
        }
        
        return dp[row][col1][col2] = dp[row][col2][col1] = max_cherries;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
        return findMaxCherries(0, 0, m - 1, n, m, grid, dp);
    }
};