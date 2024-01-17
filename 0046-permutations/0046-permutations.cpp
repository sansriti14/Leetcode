class Solution {
private:
    void findPermutation(int index, vector<int>& nums, vector<vector<int>>& permutations) {
        int n = nums.size();
        
        if(index == n) permutations.push_back(nums);
        
        for(int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            findPermutation(index + 1, nums, permutations);
            swap(nums[index], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        findPermutation(0, nums, permutations);
        return permutations;
    }
};