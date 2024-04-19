class Solution {
private:
    bool isInRange(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
    void findDFS(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        visited[row][col] = true;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int new_row = row + delta_row[i];
            int new_col = col + delta_col[i];
            
            if(isInRange(new_row, new_col, m, n) && !visited[new_row][new_col] && grid[new_row][new_col] == '1') {
                findDFS(new_row, new_col, visited, grid);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        
        int num_of_islands = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1' && !visited[row][col]) {
                    findDFS(row, col, visited, grid);
                    num_of_islands++;
                }
            }
        }
        return num_of_islands;
    }
};