//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet djSet(n);
        sort(edge.begin(), edge.end());
        
        int extra_edges = 0;
        for(auto it: edge) {
            int node = it[0];
            int adjNode = it[1];
            
            if(djSet.findParent(node) != djSet.findParent(adjNode)) {
                djSet.unionBySize(node, adjNode);
            }
            else extra_edges++;
        }
        
        int connected_comps = 0;
        for(int i=0; i<n; i++) {
            if(djSet.parent[i] == i)
                connected_comps++;
        }
        
        return (extra_edges >= connected_comps-1) ? connected_comps-1 : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends