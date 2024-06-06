class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it:hand) mp[it]++;
        
        for (auto it:mp ) pq.push(it.first);

        while (!pq.empty()) {
            int val = pq.top();
            for (int i = 0; i < groupSize; i++) {
                if (mp.find(i + val) == mp.end()) return false;

                mp[i + val]--;
                
                if (mp[i + val] == 0) {
                    if(i + val != pq.top()) return false;
                    pq.pop();
                }
            }
        }
        
        return true;
    }
};