class Solution {
private:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int &ans) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        if(x < 0 || y < 0 || x >= m || y >= n) return;
        
        if(grid1[x][y] == 0 && grid2[x][y] == 1) {
            ans = 0;
        }
        
        if(grid2[x][y] == 0) return;
        grid2[x][y] = 0;
        
        dfs(grid1, grid2, x + 1, y, ans);
        dfs(grid1, grid2, x, y + 1, ans);
        dfs(grid1, grid2, x - 1, y, ans);
        dfs(grid1, grid2, x, y - 1, ans);
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int sub_islands = 0;
        
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    int ans = 1;
                    dfs(grid1, grid2, i, j, ans);
                    sub_islands += ans;
                }
            }
        }
        return sub_islands;
    }
};