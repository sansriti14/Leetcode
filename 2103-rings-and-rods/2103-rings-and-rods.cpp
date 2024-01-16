class Solution {
public:
    int countPoints(string rings) {
        unordered_map<char, set<char>> mp;
        
        int size = rings.size();
        
        for(int i = 1; i < size; i+= 2) {
            mp[rings[i]].insert(rings[i - 1]);
        }
        
        int count = 0;
        for(auto it: mp) {
            if(it.second.size() == 3)
                count++;
        }
        
        return count;
    }
};