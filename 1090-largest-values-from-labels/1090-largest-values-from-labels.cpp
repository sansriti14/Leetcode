class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        unordered_map<int, int> freq;
        for(auto it: labels) {
            freq[it]++;
            if(freq[it] > useLimit) freq[it] = useLimit;
        }
        
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({values[i], labels[i]});
        }
        
        int max_score = 0;
        while(!pq.empty() && numWanted) {
            auto [value, label] = pq.top();
            pq.pop();
            
            if(freq[label] > 0) {
                max_score += value;
                numWanted--;
                freq[label]--;
            }
        }
        
        return max_score;
    }
};