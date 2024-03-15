class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        long long product = 1;
        int mod = 12345;
        vector<vector<int>> ans (n, vector<int> (m, 1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (ans[i][j] *= product) %= mod; 
                (product *= grid[i][j]) %= mod; 
            }
        }

        product = 1; 
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                (ans[i][j] *= product) %= mod; 
                (product *= grid[i][j]) %= mod; 
            }
        }
        
        return ans;
    }
};