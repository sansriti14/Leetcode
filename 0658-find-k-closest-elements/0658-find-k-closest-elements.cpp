class Solution {
public:
    using pii = pair<int, int>;
    
    struct comparator {
        bool operator()(const pii& a, const pii& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pii, vector<pii>, comparator> pq;
        for(auto it: arr) pq.push({abs(it - x), it});
        
        vector<int> k_closest;
        while(k--) {
            auto [diff, num] = pq.top();
            pq.pop();
            
            k_closest.push_back(num);
        }
        
        sort(begin(k_closest), end(k_closest));
        return k_closest;
    }
};