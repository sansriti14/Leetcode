class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(begin(potions), end(potions));
        vector<int> pairs;
        for(int i = 0; i < n; i++) {
            long long req = (success +  spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), req) - potions.begin();
            
            pairs.push_back(m - it);
        }
        
        return pairs;
    }
        
};