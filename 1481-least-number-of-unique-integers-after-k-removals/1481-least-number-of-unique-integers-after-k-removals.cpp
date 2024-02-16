class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto [ele, freq]: mp) {
            pq.push(freq);
        }
        
        while(!pq.empty() && k > 0) {
            auto freq = pq.top();
            pq.pop();
            
            k -= freq;
        }
        
        return (k < 0) ? pq.size() + 1 : pq.size();
    }
};