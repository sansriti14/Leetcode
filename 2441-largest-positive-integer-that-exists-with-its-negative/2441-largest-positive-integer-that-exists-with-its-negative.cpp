class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max_int = -1;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(-1 * nums[i]) != mp.end()) {
                max_int = max(max_int, abs(nums[i]));
            }
            
            else mp[nums[i]] = i;
        }
        
        return max_int;
    }
};