class Solution {
private:
    void flipRow(vector<vector<int>>& grid, int row, int n) {
        for (int j = 0; j < n; j++) {
            grid[row][j] = !grid[row][j];
        }
    }
    
    void flipCol(vector<vector<int>>& grid, int col, int m) {
        for (int i = 0; i < m; i++) {
            grid[i][col] = !grid[i][col];
        }
    }
    
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> col(n, 0);
        
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                flipRow(grid, i, n);
            }
            
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    col[j]++;
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (col[j] <= m / 2)
                flipCol(grid, j, m);
        }
        
        int ans = 0;
        int sum;
        for (vector<int> temp : grid) {
            sum = 0;
            for (int j = temp.size() - 1; j >= 0; j--) {
                if (temp[j] == 1) {
                    sum += pow(2, temp.size() - 1 - j);
                }
            }
            
            ans += sum;
        }
        
        return ans;
    }
};
