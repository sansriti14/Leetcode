class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adjList[n];
        for(auto it: edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        } 
        
        queue<int> q;
        q.push(0);
        
        vector<bool> visited (n, false);
        visited[0] = true;
        
        unordered_set<int> restrictedNodes (begin(restricted), end(restricted));
        
        int maxNodes = 0;
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            
            maxNodes++;
            
            for(auto adjNode: adjList[currNode]) {
                if(!visited[adjNode] && restrictedNodes.find(adjNode) == restrictedNodes.end()) {
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }
        
        return maxNodes;
    }
};