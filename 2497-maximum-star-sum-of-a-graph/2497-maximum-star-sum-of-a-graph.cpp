class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        
        vector<int> adjList[n];
        for (auto it: edges) {
            adjList[it[0]].push_back(vals[it[1]]);
            adjList[it[1]].push_back(vals[it[0]]);
        }
        
        int maxStarSum = INT_MIN;
        
        for (int node = 0; node < n; node++) {
            sort(begin(adjList[node]), end(adjList[node]), greater<int>());
            
            int currStarSum = vals[node];
                
            for (int i = 0; i < min(k, (int)adjList[node].size()); i++) {
                if (adjList[node][i] < 0) break;

                currStarSum += adjList[node][i];
            }

            maxStarSum = max(maxStarSum, currStarSum);
            
        }
        
        return maxStarSum;
    }
};