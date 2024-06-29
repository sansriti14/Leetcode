class Solution {
private:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &curr, vector<bool> &visited) {
        visited[node] = true;
        
        for (auto adjNode : adjList[node]) {
            if (!visited[adjNode]) {
                curr.push_back(adjNode);
                dfs(adjNode, adjList, curr, visited);
            }
        }
    }
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        
        for (auto it: edges) {
            adjList[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            vector<int> curr;
            
            dfs(i, adjList, curr, visited);
            sort(curr.begin(), curr.end());
            ans[i] = curr;
        }
        
        return ans;
    }
};