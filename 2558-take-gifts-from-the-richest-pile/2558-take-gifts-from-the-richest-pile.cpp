class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long total_gifts = 0;
        for(auto it: gifts) {
            total_gifts += it;
        }
        
        priority_queue<int> pq(begin(gifts), end(gifts));
        while(k-- && !pq.empty()) {
            long long num_gifts = pq.top();
            pq.pop();
            
            long long remaining = sqrt(num_gifts);
            total_gifts -= (num_gifts - remaining);
            pq.push(remaining);
        }
        
        return total_gifts;
    }
};