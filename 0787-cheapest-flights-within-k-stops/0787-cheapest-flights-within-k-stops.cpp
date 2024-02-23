class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjList[n];
        for(auto it: flights) {
            adjList[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> price (n, 1e9);
        price[src] = 0;
        
        while(!q.empty()) {
            int curr_stops = q.front().first;
            int curr_city = q.front().second.first;
            int curr_price = q.front().second.second;
            q.pop();
            
            if(curr_stops <= k) {
                for(auto it: adjList[curr_city]) {
                    int adj_city = it.first;
                    int new_price = curr_price + it.second;
                    
                    if(new_price < price[adj_city]) {
                        price[adj_city] = new_price;
                        q.push({curr_stops + 1, {adj_city, new_price}});
                    }
                }
            } 
        }
        
        return (price[dst] == 1e9) ? -1 : price[dst];
    }
};