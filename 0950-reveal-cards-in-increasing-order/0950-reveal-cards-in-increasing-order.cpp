class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(begin(deck), end(deck));
        
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        
        vector<int>ans(n);
        for (int i = 0 ; i < n ; i++) {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        
        return ans;
    }
};