class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();;
        
        unordered_map<char, int> mp;
        for(auto it: tasks) mp[it]++;
        
        priority_queue<int> pq;
        for(auto it: mp) pq.push(it.second);
        
        int min_time = 0;
        while(!pq.empty()) {
            vector<int> count;
            
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    
                    if (--freq > 0) {
                        count.push_back(freq);
                    }
                    
                    min_time++;
                }
                
                else if (!count.empty()) {
                        min_time++;
                }
            }
            
            for (int it : count) {
                pq.push(it);
            }
        }
        
        return min_time;
    }
};