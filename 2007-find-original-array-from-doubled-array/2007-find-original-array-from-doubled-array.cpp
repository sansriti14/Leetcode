class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2) return {};
        
        sort(changed.begin(), changed.end());
        
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[changed[i]]++;
        }
        
        vector<int> original_array;
        for(int i = 0; i < n; i++) {
            if(mp[changed[i]] == 0) continue;
            if(mp[changed[i] * 2] == 0) return {};
            
            original_array.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i] * 2]--;
            
        }
        
        return original_array;
    }
};