class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ranks = arr;
        sort(begin(arr), end(arr));
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int rank = 1;
        for(int i = 0; i < n; i++) {
            if(mp.find(arr[i]) == mp.end())
                mp[arr[i]] = rank++;
        };
        
        for(int i = 0; i < n; i++) {
            ranks[i] = mp[ranks[i]];
        }
        
        return ranks;
    }
};