class DisjointSet {
  public:
    vector<int> parent, size;
    DisjointSet (int V) {
        parent.resize(V+1);
        size.resize(V+1, 1);
        
        for(int i=0; i<V; i++) parent[i] = i;
    }
    
    int findParent (int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        
        if(parent_u == parent_v) return;
        
        if(size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n) {
        return (row>=0 && row<n && col>=0 && col<n);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0) continue;
                
                for(int i=0; i<4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]) {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        
        int max_size = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1) continue;
                
                set<int> adjSize;
                for(int i=0; i<4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]) {
                        adjSize.insert(ds.findParent(nrow * n + ncol));
                    }
                }
                
                int curr_size = 0;
                for(auto it: adjSize)
                    curr_size += ds.size[it];
                max_size = max(max_size, curr_size + 1);
            }
        }
        
        for(int i=0; i<n*n; i++)
            max_size = max(max_size, ds.size[ds.parent[i]]);
        
        return max_size;
    }
};