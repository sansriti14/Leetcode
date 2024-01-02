class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1);
        
        vector<vector<int>> ans;
        for (auto num : nums) {
            if (freq[num] >= ans.size()) {
                ans.push_back({});
            }
            
            
            ans[freq[num]].push_back(num);
            freq[num]++;
        }
        
        return ans;
    }
};