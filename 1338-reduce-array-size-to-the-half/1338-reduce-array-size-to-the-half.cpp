class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        
        priority_queue<int> pq;
        for(auto it: mp) pq.push(it.second);
        
        int min_size = 0;
        while(!pq.empty()) {
            int freq = pq.top();
            pq.pop();
            
            n -= freq;
            min_size++;
            if(n <= arr.size() / 2) return min_size;
        }
        
        return min_size;
    }
};