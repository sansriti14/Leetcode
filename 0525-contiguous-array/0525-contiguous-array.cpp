class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int currSum = 0;
        int maxLength = 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            currSum += (nums[i] == 1) ? 1 : -1;
            
            if(mp.find(currSum) != mp.end()) {
                maxLength = max(maxLength, i - mp[currSum]);
            }
            
            else mp[currSum] = i;
        }
        
        return maxLength;
    }
};