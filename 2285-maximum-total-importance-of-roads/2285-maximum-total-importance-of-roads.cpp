class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;
        for(auto it: roads) {
            mp[it[0]]++;
            mp[it[1]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        
        long long max_importance = 0;
        while(!pq.empty()) {
            auto [freq, city] = pq.top();
            pq.pop();
            
            max_importance += ((long long)freq * (n--));
        }
        
        return max_importance;
    }
};