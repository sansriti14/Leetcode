class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        
        unordered_map<char, int> mp;
        for(auto ch: s) {
            mp[ch]++;
            
            if(mp[ch] > (n + 1)/2) return "";
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        
        string str = "";
        while(pq.size() > 1) {
            auto [freq1, char1] = pq.top();
            pq.pop();
            
            auto [freq2, char2] = pq.top();
            pq.pop();
            
            str += char1;
            str += char2;
            
            if(--freq1 > 0) pq.push({freq1, char1});
            if(--freq2 > 0) pq.push({freq2, char2});
        }
        
        if(!pq.empty()) str += pq.top().second;
        
        return str;
    }
};