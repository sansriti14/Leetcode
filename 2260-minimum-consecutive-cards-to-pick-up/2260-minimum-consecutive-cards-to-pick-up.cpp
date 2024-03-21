class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_set<int> st;
        
        int minCards = n + 1;
        int i = 0, j = 0;
        while(j < n) {
            if(st.find(cards[j]) != st.end()) {
                minCards = min(minCards, (int)st.size() + 1);
                st.erase(cards[i]);
                i++;
            }
            
            else {
                st.insert(cards[j]);
                j++;
            }
        } 
        
        return (minCards == n + 1) ? -1 : minCards;
    }
};