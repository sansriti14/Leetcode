using pii = pair<int, int>;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for(int i = 0; i < n; i++) {
            pq.push({capacity[i] - rocks[i], i});
        }
        
        while(additionalRocks && !pq.empty()) {
            auto [canPlace, index] = pq.top();
            pq.pop();
            
            if(additionalRocks >= canPlace) {
                additionalRocks -= canPlace;
                rocks[index] = capacity[index];
            }
            
            else {
                additionalRocks = 0;
            }
        }
        
        int max_bags = 0;
        for(int i = 0; i < n; i++) {
            if(rocks[i] == capacity[i]) max_bags++;
        }
        
        return max_bags;
    }
};