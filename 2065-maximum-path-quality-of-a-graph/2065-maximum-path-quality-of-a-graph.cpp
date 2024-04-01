class Solution {
private:
    void dfs(vector<int>& values, int currNode, int currTime, int maxTime, int currQuality, int& maxQuality, vector<pair<int, int>> adjList[], vector<int>& visited) {
        if (currTime > maxTime) return;

        if (visited[currNode] == 0) currQuality += values[currNode];

        visited[currNode]++;

        if (currNode == 0) {
            maxQuality = max(maxQuality, currQuality);
        }

        for (auto it: adjList[currNode]) {
            int adjNode = it.first;
            int newTime = currTime + it.second; 
            dfs(values, adjNode, newTime, maxTime, currQuality, maxQuality, adjList, visited);
        }

        visited[currNode]--;
    }
    
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int, int>> adjList[n];
        for (auto it: edges) {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }

        int maxQuality = 0;
        vector<int> visited(n, 0);
        dfs(values, 0, 0, maxTime, 0, maxQuality, adjList, visited);
        
        return maxQuality;
    }
};
