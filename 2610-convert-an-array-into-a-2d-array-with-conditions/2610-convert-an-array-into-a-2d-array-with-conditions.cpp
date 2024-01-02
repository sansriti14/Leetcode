class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int num_rows = 0, most_freq = -1;
        for(auto it: nums) {
            mp[it]++;
            num_rows = max(num_rows, mp[it]);
        }
        
        vector<vector<int>> ans(num_rows);
        for(auto it: mp){
            int num = it.first;
            int freq = it.second;

            for(int i = 0; i < freq; i++){
                ans[i].push_back(num);
            }
        }
        
        return ans;
    }
};