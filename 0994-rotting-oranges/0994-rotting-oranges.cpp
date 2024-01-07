class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) 
                    q.push({{i, j}, 0});
            }
        }
        
        int min_time = 0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            min_time = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int drow = row + dr[i];
                int dcol = col + dc[i];
                
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && grid[drow][dcol] == 1 && visited[drow][dcol] != 2) {
                    visited[drow][dcol] = 2;
                    q.push({{drow, dcol}, min_time+1});
                }
            }  
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && visited[i][j] != 2) 
                    return -1;
            }
        }
        
        return min_time;
    }
};