class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        
        for (int r = 0; r < n - 2; r++) {
            for (int c = 0; c < n - 2; c++) {
                for (int i = r; i < r + 3; i++) {
                    for (int j = c; j < c + 3; j++) {
                        ans[r][c] = max(ans[r][c], grid[i][j]);
                    }
                }
            }
        }
        
        return ans;
    }
};