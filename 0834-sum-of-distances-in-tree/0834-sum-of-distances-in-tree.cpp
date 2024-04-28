class Solution {
private:
    void dfs1(vector<int> adjList[], vector<int>& child, int length, int root, vector<bool>& visited,vector<int> &ans){
        visited[root] = true;
        ans[0] += length;
        length++;
        
        for(auto& it: adjList[root]){
            if(visited[it]) continue;
            dfs1(adjList, child, length, it, visited, ans);
            child[root] += child[it];
        }
        
        child[root] += 1;
    }
    
    void dfs2(vector<int> adjList[], vector<int>& child, int root, vector<bool>& visited, int n, vector<int>& ans){
        visited[root] = true;
        
        for(auto& it: adjList[root]){
            if(visited[it]) continue;
            ans[it] = ans[root] - child[it] + n - child[it];
            dfs2(adjList, child, it, visited, n, ans);
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        for(auto& it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> ans(n);
        vector<int> child(n);
        vector<bool> visited(n);
        
        dfs1(adjList, child, 0, 0, visited, ans);
        for(int i = 0; i < n; i++) visited[i] = false;
        
        dfs2(adjList, child, 0, visited, n, ans);
        
        return ans;
    }
};