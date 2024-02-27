class Solution {
private:
    void findSubsets(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        int n = nums.size();
        if(index == n) {
            ans.push_back(temp);
            return;
        }
        
        findSubsets(index + 1, nums, temp, ans);
        temp.push_back(nums[index]);
        findSubsets(index + 1, nums, temp, ans);
        temp.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsets(0, nums, temp, ans);
        return ans;
    }
};