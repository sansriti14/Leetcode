class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>> pq; 
        for(auto it: map){
            pq.push({it.second, it.first});
            if(pq.size() > (int)map.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};