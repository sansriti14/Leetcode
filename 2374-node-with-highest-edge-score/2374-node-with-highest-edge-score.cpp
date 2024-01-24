class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, long long> edge_scores;
        for(int i = 0; i < edges.size(); i++) {
            edge_scores[edges[i]] = (long long)(i + edge_scores[edges[i]]);
        }
        
        int ans = -1;
        long long max_score = -1;
        for(auto it: edge_scores) {
            if(it.second > max_score) {
                max_score = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
};