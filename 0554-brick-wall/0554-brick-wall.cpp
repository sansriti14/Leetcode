class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        
        vector<set<int>> prefix(n);
        unordered_map<int, int> mp;
        
        for(int row = 0; row < n; row++) {
            int sum = 0;
            for(int col = 0; col < wall[row].size() - 1; col++) {
                sum += wall[row][col];
                prefix[row].insert(sum);
                mp[sum]++;
            }
        }
        
        int most_common = 0, most_count = 0;
        for(auto it: mp) {
            if(it.second > most_count) {
                most_common = it.first;
                most_count = it.second;
            }
        }
        
        cout<<most_common<<endl;
        
        int min_crossed = 0;
        for(int row = 0; row < n; row++) {
            if(prefix[row].find(most_common) == prefix[row].end())
                min_crossed++;
        }
        
        return min_crossed;
    }
};