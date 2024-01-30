class Solution {
private:
    int findMinCost(int curr_row, int curr_col, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(curr_row == m - 1) {
            return grid[curr_row][curr_col];
        }
        
        if(dp[curr_row][curr_col] != -1) return dp[curr_row][curr_col];
        
        int min_cost = 1e9;
        for(int next_col = 0; next_col < n; next_col++) {
            min_cost = min(min_cost, moveCost[grid[curr_row][curr_col]][next_col] + grid[curr_row][curr_col] + findMinCost(curr_row + 1, next_col, grid, moveCost, dp));
        }
        
        return dp[curr_row][curr_col] = min_cost;
    }
    
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, -1));
        
        int min_cost = 1e9;
        for(int col = 0; col < n; col++) {
            min_cost = min(min_cost, findMinCost(0, col, grid, moveCost, dp));
        }
        
        return min_cost;
    }
};