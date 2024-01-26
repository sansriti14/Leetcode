class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
private:
    int mod = 1e9 + 7;
    
    int countPaths(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>>& dp) {
        if(!isValid(row, col, m, n)) return 1;
        if(maxMove <= 0) return 0;      
        
        if(dp[maxMove][row][col] != -1) return dp[maxMove][row][col];
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        long long paths = 0;
        for(int i = 0; i < 4; i++) {
            int adj_row = row + delta_row[i];
            int adj_col = col + delta_col[i];
            
            paths = (paths + countPaths(m, n, maxMove - 1, adj_row, adj_col, dp)) % mod;
        }
        
        return dp[maxMove][row][col] = paths % mod;
    } 
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp (maxMove + 1, vector<vector<int>> (m +1, vector<int> (n + 1, -1)));
        return countPaths(m, n, maxMove, startRow, startColumn, dp);
    }
};