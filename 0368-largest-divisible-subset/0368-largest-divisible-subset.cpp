class Solution {
private: 
    void findLargestSubset(int index, vector<int>& nums, vector<int>& temp, vector<int>& ans, vector<int>& dp) {
        int n = nums.size();
        if(index >= n) {
            if(temp.size() > ans.size()) ans = temp;
            return;
        }
        
        findLargestSubset(index + 1, nums, temp, ans, dp);
        
        if((temp.size() == 0) || (temp.size() > dp[index] && (nums[index] % temp.back() == 0))) {
            dp[index] = temp.size();
            temp.push_back(nums[index]);
            findLargestSubset(index + 1, nums, temp, ans, dp);
            temp.pop_back();
        }
    }
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        vector<int> dp (n + 1 -1);
        vector<int> ans;
        vector<int> temp;
        
        findLargestSubset(0, nums, temp, ans, dp);
        return ans;
    }
};