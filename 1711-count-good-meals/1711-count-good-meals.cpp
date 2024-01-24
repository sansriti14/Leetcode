class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> mp;
        
        int good_meals = 0;
        int mod = 1e9 + 7;
        for(auto it: deliciousness) {
            for(int i = 1; i < (1 << 22); i *= 2) {
                if(mp.find(i - it) != mp.end()) {
                    good_meals = (good_meals + mp[i - it]) % mod;
                }
            }
            
            mp[it]++;
        }
        
        return good_meals;
    }
};