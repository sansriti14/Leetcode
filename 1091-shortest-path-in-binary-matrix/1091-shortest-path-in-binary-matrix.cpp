class Solution {
private: 
    bool isValid(int row, int col, int n) {
        return (row >= 0 && col >= 0 && row < n && col < n);
    } 
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance (n, vector<int> (n, 1e8));
        
        q.push({1, {0, 0}}); 
        distance[0][0] = 1;
        
        int delta_row[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int delta_col[] = {1, 1, 0, -1, -1, 0, -1, 1};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int curr_distance = it.first;
            int curr_row = it.second.first;
            int curr_col = it.second.second;
            
            if(curr_row == n - 1 && curr_col == n - 1) return curr_distance;
            
            for(int i = 0; i < 8; i++) {
                int adj_row = curr_row + delta_row[i];
                int adj_col = curr_col + delta_col[i];
                
                if(isValid(adj_row, adj_col, n) && grid[adj_row][adj_col] == 0 && distance[adj_row][adj_col] > curr_distance + 1) {
                    q.push({curr_distance + 1, {adj_row, adj_col}});
                    distance[adj_row][adj_col] = curr_distance + 1;
                }
            }
        }
        
        return -1;
    }
};