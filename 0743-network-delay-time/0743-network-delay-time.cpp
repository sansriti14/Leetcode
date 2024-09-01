class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        
        for (auto it : times) {
            adjList[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> time(n + 1, 1e9);
        vector<bool> visited(n + 1, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
        time[k] = 0;
        
        while (!pq.empty()) {
            auto [curr_time, source] = pq.top();
            pq.pop();
            
            if (visited[source]) continue;
            visited[source] = true;
            
            for (auto it : adjList[source]) {
                int target = it.first;
                int time_taken = it.second;
                
                if (time[target] > curr_time + time_taken) {
                    time[target] = curr_time + time_taken;
                    pq.push({time[target], target});
                }
            }
        }
        
        int min_time = *max_element(time.begin() + 1, time.end());
        return (min_time == 1e9) ? -1 : min_time;
    }
};
