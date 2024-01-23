using pii = pair<int, int>;

class Solution {
public:
    struct comparator {
        bool operator()(const pii& a, const pii& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto it: nums) freq[it]++;
        
        priority_queue<pii, vector<pii>, comparator> pq;
        for(auto it: freq) pq.push({it.second, it.first});
        
        int index = 0;
        while(!pq.empty()) {
            auto [freq, num] = pq.top();
            pq.pop();
            
            while(freq--) {
                nums[index++] = num;
            }
        }
        
        return nums;
    }
};