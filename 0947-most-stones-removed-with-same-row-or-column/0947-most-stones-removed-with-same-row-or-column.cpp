class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet (int V) {
            parent.resize(V+1);
            size.resize(V+1, 1);
            
            for(int i=0; i<V; i++)
                parent[i] = i;
        }
        
        int findParent (int node) {
            if(parent[node] == node)
                return node;
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 2);
        
        for(auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
        }
        
        int no_of_comps = 0;
        for(int i = 0; i < maxRow + maxCol + 2; i++) {
            if(ds.findParent(i) == i && ds.size[i] > 1) no_of_comps++;
        }
        
        return stones.size() - no_of_comps;
    }
};