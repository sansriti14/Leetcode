class DisjointSet {
    public:
    vector<int> parent, size;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
        size.resize(n  + 1);
    }
    
    int findParent(int node) {
        if(parent[node] == node) return node;
        else return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        
        if(parent_u == parent_v) return;
        
        else if(size[parent_u] <= size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        
        else if(size[parent_v] < size[parent_u]) {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
    pair<int, int> move(int row, int col, string direction) {
        if(direction == "left") return {row, col - 1};
        else if(direction == "right") return {row, col + 1};
        else if(direction == "up") return {row - 1, col};
        
        return {row + 1, col};
    }
    
public:
    bool hasValidPath(vector<vector<int>>& grid) { 
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 5) return false;
        DisjointSet djs(n * m);
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                int street = grid[row][col];
                int node = (row * m) + col;
                
                if(street == 1) {
                    auto [left_row, left_col] = move(row, col, "left");
                    if(isValid(left_row, left_col, n, m)) {
                        int adj_street = grid[left_row][left_col];
                        if(adj_street == 1 || adj_street == 4 || adj_street == 6) {
                            int adj_node = (left_row * m) + left_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [right_row, right_col] = move(row, col, "right");
                    if(isValid(right_row, right_col, n, m)) {
                        int adj_street = grid[right_row][right_col];
                        if(adj_street == 1 || adj_street == 3 || adj_street == 5) {
                            int adj_node = (right_row * m) + right_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }

                else if(street == 2) {
                    auto [up_row, up_col] = move(row, col, "up");
                    if(isValid(up_row, up_col, n, m)) {
                        int adj_street = grid[up_row][up_col];
                        if(adj_street == 2 || adj_street == 3 || adj_street == 4) {
                            int adj_node = (up_row * m) + up_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [down_row, down_col] = move(row, col, "down");
                    if(isValid(down_row, down_col, n, m)) {
                        int adj_street = grid[down_row][down_col];
                        if(adj_street == 2 || adj_street == 5 || adj_street == 6) {
                            int adj_node = (down_row * m) + down_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }

                else if(street == 3) {
                    auto [left_row, left_col] = move(row, col, "left");
                    if(isValid(left_row, left_col, n, m)) {
                        int adj_street = grid[left_row][left_col];
                        if(adj_street == 1 || adj_street == 4 || adj_street == 6) {
                            int adj_node = (left_row * m) + left_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [down_row, down_col] = move(row, col, "down");
                    if(isValid(down_row, down_col, n, m)) {
                        int adj_street = grid[down_row][down_col];
                        if(adj_street == 2 || adj_street == 5 || adj_street == 6) {
                            int adj_node = (down_row * m) + down_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }

                else if(street == 4) {
                    auto [right_row, right_col] = move(row, col, "right");
                    if(isValid(right_row, right_col, n, m)) {
                        int adj_street = grid[right_row][right_col];
                        if(adj_street == 1 || adj_street == 3 || adj_street == 5) {
                            int adj_node = (right_row * m) + right_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [down_row, down_col] = move(row, col, "down");
                    if(isValid(down_row, down_col, n, m)) {
                        int adj_street = grid[down_row][down_col];
                        if(adj_street == 2 || adj_street == 5 || adj_street == 6) {
                            int adj_node = (down_row * m) + down_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }

                else if(street == 5) {
                    auto [left_row, left_col] = move(row, col, "left");
                    if(isValid(left_row, left_col, n, m)) {
                        int adj_street = grid[left_row][left_col];
                        if(adj_street == 1 || adj_street == 4 || adj_street == 6) {
                            int adj_node = (left_row * m) + left_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [up_row, up_col] = move(row, col, "up");
                    if(isValid(up_row, up_col, n, m)) {
                        int adj_street = grid[up_row][up_col];
                        if(adj_street == 2 || adj_street == 3 || adj_street == 4) {
                            int adj_node = (up_row * m) + up_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }

                else if(street == 6) {
                    auto [up_row, up_col] = move(row, col, "up");
                    if(isValid(up_row, up_col, n, m)) {
                        int adj_street = grid[up_row][up_col];
                        if(adj_street == 2 || adj_street == 3 || adj_street == 4) {
                            int adj_node = (up_row * m) + up_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }

                    auto [right_row, right_col] = move(row, col, "right");
                    if(isValid(right_row, right_col, n, m)) {
                        int adj_street = grid[right_row][right_col];
                        if(adj_street == 1 || adj_street == 3 || adj_street == 5) {
                            int adj_node = (right_row * m) + right_col;
                            djs.unionBySize(node, adj_node);
                        }
                    }
                }
            }
        }
        
        return djs.findParent(0) == djs.findParent(n * m - 1);
    }
};