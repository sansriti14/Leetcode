class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int findParent(int node) {
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
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        
        for(auto it: edges) {
            ds.unionBySize(it[0], it[1]);
        }
        
        if(ds.findParent(source) == ds.findParent(destination)) return true;
        return false;
    }
};