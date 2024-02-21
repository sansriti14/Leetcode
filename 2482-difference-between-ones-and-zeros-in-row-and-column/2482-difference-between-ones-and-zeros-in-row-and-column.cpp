class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row_ones(m, 0);
        vector<int> col_ones(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_ones[i] += grid[i][j];
                col_ones[j] += grid[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 2 * (row_ones[i] + col_ones[j]) - m - n;
            }
        }

        return grid;
    }
};
