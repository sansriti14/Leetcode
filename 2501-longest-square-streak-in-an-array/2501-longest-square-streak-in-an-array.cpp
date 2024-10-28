class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> st (begin(nums), end(nums));
        
        unordered_map<int, int> mp;
        int maxLength = -1;
        
        for (auto it: st) {
            int root = sqrt(it);
            if (root * root == it) {
                mp[it] = 1 + mp[root];
            }
            
            else mp[it] = 1;
            
            maxLength = max(maxLength, mp[it]);
        }
        
        return (maxLength < 2) ? -1 : maxLength;
    }
};