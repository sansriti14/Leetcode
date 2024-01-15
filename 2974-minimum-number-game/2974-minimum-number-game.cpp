class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<int> arr;
        int n = nums.size();
        
        for(int i = 1; i < n; i += 2) {
            arr.push_back(nums[i]);
            arr.push_back(nums[i - 1]);
        } 
        
        return arr;
    }
};