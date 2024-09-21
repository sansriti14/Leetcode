class Solution {
private:
    bool bfs(vector<vector<int>>& adjList, int start, int end, vector<bool>& visited) {
        if (start == end) return true; 
        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            visited[node] = true; 
            if(node == end) return true;
            
            for(auto adjNode  : adjList[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true; 
                    q.push(adjNode);
                }
            }
        }

        return false; 
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n + 1);
        vector<bool> visited(n + 1, false);
        
        for (auto it : edges) {
            fill(visited.begin(), visited.end(), 0);  
            if (!adjList[it[0]].empty() && !adjList[it[1]].empty() && bfs(adjList, it[0], it[1], visited)) {
                return it;
            }
            
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        return {};
    }
};