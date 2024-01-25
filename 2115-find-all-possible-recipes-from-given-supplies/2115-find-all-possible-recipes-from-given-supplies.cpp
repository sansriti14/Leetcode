class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> edges;
        unordered_map<string, int> indegree;
        
        for (int i = 0; i < n; i++) {
            for (auto ingredient: ingredients[i]) {
                edges[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for(auto it: supplies) q.push(it);
        
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            
            for(auto it: edges[curr]) {
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        
        vector<string> ans;
        for(auto it: recipes) {
            if(indegree[it] == 0) ans.push_back(it);
        }
        
        return ans;
    }
};