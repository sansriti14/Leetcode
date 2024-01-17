class Solution {
private:
    void findPermutations(int index, vector<int> nums, vector<vector<int>>& unique_permutations) {
        int n = nums.size();
        
        if(index == n - 1) {
            unique_permutations.push_back(nums);
            return;
        }
        
        for(int i = index; i < n; i++) {
            if (index != i && nums[i] == nums[index]) continue;
            swap(nums[index], nums[i]);
            findPermutations(index + 1, nums, unique_permutations);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> unique_permutations;
        
        findPermutations(0, nums, unique_permutations);
    
        return unique_permutations;
    }
};