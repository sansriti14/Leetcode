class Solution {
    int m, n;    
    
private:
    int countNumberOfPaths(int currRow, int currCol, int currSum, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(currRow >= m || currCol >= n) return 0;
        
        currSum += grid[currRow][currCol];
        if(currRow == m - 1 && currCol == n - 1) {
            return (currSum % k == 0);
        }
        
        if(dp[currRow][currCol][currSum % k] != -1) return dp[currRow][currCol][currSum % k];
        
        int right = countNumberOfPaths(currRow, currCol + 1, currSum, k, grid, dp);
        int down = countNumberOfPaths(currRow + 1, currCol, currSum, k, grid, dp);
        
        int mod = 1e9 + 7;
        return dp[currRow][currCol][currSum % k] = (right + down) % mod;
    }
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int> (k, -1)));
        return countNumberOfPaths(0, 0, 0, k, grid, dp);
    }
};