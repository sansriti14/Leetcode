class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        visited[row][col] = true;
        
        queue<pair<int, int>> bfs;
        bfs.push({row, col});
        
        while(!bfs.empty()) {
            int curr_row = bfs.front().first;
            int curr_col = bfs.front().second;
            bfs.pop();
            
            int curr_color = grid[curr_row][curr_col];
            
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            
            int count = 0;
            for(int i = 0; i < 4; i++) {
                int adj_row = curr_row + delta_row[i]; 
                int adj_col = curr_col + delta_col[i];
                
                if(isValid(adj_row, adj_col, m, n)) {
                    if(visited[adj_row][adj_col] == true) count++;
                    else if(grid[adj_row][adj_col] == curr_color) {
                        count++;
                        visited[adj_row][adj_col] = true;
                        bfs.push({adj_row, adj_col});
                    }
                }
            }
            
            if(count != 4) grid[curr_row][curr_col] = color;
        }
        
        return grid;
    }
};