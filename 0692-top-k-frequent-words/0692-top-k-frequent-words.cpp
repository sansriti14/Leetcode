using pis = pair<int, string>;

class Solution {
public:
    struct comparator {
        bool operator()(const pis& a, const pis& b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto word: words) {
            mp[word]++;
        }
        
        priority_queue<pis, vector<pis>, comparator> pq;
        for (auto it: mp) {
            pq.push({it.second, it.first});
        }
        
        vector<string> topk_frequent;
        while(k--) {
            topk_frequent.push_back(pq.top().second);
            pq.pop();
        }
        
        return topk_frequent;
    }
};