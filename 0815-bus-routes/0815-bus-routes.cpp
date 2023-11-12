class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> mp;
        for(int bus = 0; bus < routes.size(); bus++) {
            for(auto stop: routes[bus]) {
                mp[stop].push_back(bus);
            }
        }
        
        queue<pair<int, int>> bfs;
        bfs.push({source, 0});
        
        unordered_map<int, bool> bus_taken;
        bus_taken[source] = true;
        
        while(!bfs.empty()) {
            int stop = bfs.front().first;
            int num_of_buses = bfs.front().second;
            bfs.pop();
            
            if(stop == target) return num_of_buses;
            
            for(auto i: mp[stop]) {
                for(auto j: routes[i]) {
                    if(bus_taken.find(j) == bus_taken.end()) {
                        bus_taken[j] = true;
                        bfs.push({j, num_of_buses+1});
                    }
                }
                routes[i].clear();
            }
        }
        
        return -1;
    }
};