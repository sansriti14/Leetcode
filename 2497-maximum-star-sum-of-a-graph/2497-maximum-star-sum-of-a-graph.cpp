class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adjList(n);
        
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(vals[edge[1]]);
            adjList[edge[1]].push_back(vals[edge[0]]);
        }
        
        int maxStarSum = INT_MIN;
        
        for (int node = 0; node < n; node++) {
            sort(begin(adjList[node]), end(adjList[node]), greater<int>()); 
            
            int currStarSum = vals[node];
            
            for (int i = 0; i < min(k, (int)adjList[node].size()); i++) {
                if (adjList[node][i] > 0) {
                    currStarSum += adjList[node][i];
                } 
                
                else break;
            }
            
            maxStarSum = max(maxStarSum, currStarSum);
        }
        
        return maxStarSum;
    }
};
