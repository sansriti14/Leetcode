class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int V) {
        parent.resize(V + 1);
        size.resize(V + 1, 1);

        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if (parent_u == parent_v)
            return;

        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        } else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }

    bool haveSameParent(int first, int second) {
        return (findParent(first) == findParent(second));
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n);

        int alice = 0, bob = 0, both = 0;

        for (auto it : edges) {
            int type = it[0];
            int node1 = it[1];
            int node2 = it[2];
            if (type == 1 || type == 2)
                continue;
            if (ds1.haveSameParent(node1, node2) && ds2.haveSameParent(node1, node2)) {
                both++;
            } else {
                ds1.unionBySize(node1, node2);
                ds2.unionBySize(node1, node2);
            }
        }
        for (auto it : edges) {
            int type = it[0];
            int node1 = it[1];
            int node2 = it[2];
            if (type == 1) {
                if (ds1.haveSameParent(node1, node2))
                    alice++;
                else
                    ds1.unionBySize(node1, node2);
            } else if (type == 2) {
                if (ds2.haveSameParent(node1, node2))
                    bob++;
                else
                    ds2.unionBySize(node1, node2);
            }
        }

        unordered_set<int> st1;
        unordered_set<int> st2;
        for (int i = 1; i <= n; i++) {
            st1.insert(ds1.findParent(i));
            if (st1.size() > 1)
                break;
        }
        
        for (int i = 1; i <= n; i++) {
            st2.insert(ds2.findParent(i));
            if (st2.size() > 1)
                break;
        }

        return (st1.size() == 1 && st2.size() == 1) ? alice + bob + both : -1;
    }
};