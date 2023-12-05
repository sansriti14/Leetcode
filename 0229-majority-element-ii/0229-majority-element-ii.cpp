class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(auto it: nums) 
            m[it]++;
        
        for(auto it: m) {
            if(it.second > n/3) {
                if(ans.empty() || ans.back() != it.first)
                    ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};