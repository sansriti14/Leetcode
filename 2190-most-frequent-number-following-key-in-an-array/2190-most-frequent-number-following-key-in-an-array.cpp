class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == key) mp[nums[i + 1]]++;
        }
        
        int target = -1, count = -1;
        for(auto it: mp) {
            if(it.second > count) {
                target = it.first;
                count = it.second;
            }
        }
        
        return target;
    }
};