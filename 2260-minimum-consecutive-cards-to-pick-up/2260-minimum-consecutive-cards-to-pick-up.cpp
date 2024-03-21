class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        
        unordered_map<int,int> mp;
        int minCards = n + 1;
        
        for(int i = 0; i < n; i++) {
            if(mp.find(cards[i]) != mp.end()) {
                minCards = min(minCards, i - mp[cards[i]] + 1);
            }
            
            mp[cards[i]] = i;
        }
        
        return (minCards == n + 1) ? -1 : minCards;
    }
};