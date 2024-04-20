class Solution {
public:
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int r, int c, int n, int m)
    {
        if(r>=0 && r<n && c>=0 && c<m)
            return true;
        return false;
    }
    
    void dfsHelper(int r, int c, vector<vector<int>>&land, int &r1, int &c1, int &r2, int &c2){
        land[r][c] = 0;
        
        for(int i=0; i<4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(isValid(nr, nc, land.size(), land[0].size()) && land[nr][nc]==1)
            {
                r1 = min(r1, nr);
                c1 = min(c1, nc);
                r2 = max(r2, nr);
                c2 = max(c2, nc);
                dfsHelper(nr, nc, land, r1, c1, r2, c2);
            }
            
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int i, j;
        int n = land.size(), m = land[0].size();
        
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(land[i][j])
                {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    dfsHelper(i, j, land, r1, c1, r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        
        return ans;
    }
};