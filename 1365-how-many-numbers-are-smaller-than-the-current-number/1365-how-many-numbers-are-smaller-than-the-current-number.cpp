class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto it: nums) mp[it]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto it: mp) pq.push({it.first, it.second});
        
        int k = 1;
        while(!pq.empty()) {
            auto [num, freq] = pq.top();
            pq.pop();
            
            mp[num] = (n - k) - (freq - 1);
            while(freq--) k++;
        }
        
        for(int i = 0; i < n; i++) {
            nums[i] = mp[nums[i]];
        }
        
        return nums;
    }
};