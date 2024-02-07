class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;
        
        sort(begin(nums), end(nums));
        for(auto it: nums) {
            if(mp[it] == 0) continue;
            
            mp[it]--;
            for(int i = 1; i < k; i++) {
                if(mp[it + i] == 0) return false;
                mp[it + i]--;
            }
        }
        
        return true;
    }
};