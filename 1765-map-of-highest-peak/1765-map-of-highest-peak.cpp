class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }
    
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        queue<pair<int, int>> bfs;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                isWater[row][col] = (isWater[row][col] == 1) ? 0 : -1;
                if(isWater[row][col] == 0)
                    bfs.push({row,col});
            }
        }
        
        int height = 1;
        while(!bfs.empty()) {
            int size = bfs.size();
            while(size--) {
                int curr_row = bfs.front().first;
                int curr_col = bfs.front().second;
                bfs.pop();

                int delta_row[] = {-1, 0, 1, 0};
                int delta_col[] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++) {
                    int adj_row = curr_row + delta_row[i];
                    int adj_col = curr_col + delta_col[i];

                    if(isValid(adj_row, adj_col, m, n) && isWater[adj_row][adj_col] == -1) {
                        isWater[adj_row][adj_col] = height;
                        bfs.push({adj_row, adj_col});
                    }
                }
            }   
            height++;
        }
        
        return isWater;
    }
};