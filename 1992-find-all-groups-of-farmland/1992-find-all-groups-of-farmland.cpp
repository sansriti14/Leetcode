class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> ans;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (land[r][c] == 0) continue;
                
                int x = r, y = c;
                for (x = r; x < m && land[x][c]; x++) {
                    for (y = c; y < n && land[x][y]; y++) {
                        land[x][y] = 0;
                    }
                } 
                
                ans.push_back({r, c, x - 1, y - 1});
            }
        }
        
        return ans;
    }
};