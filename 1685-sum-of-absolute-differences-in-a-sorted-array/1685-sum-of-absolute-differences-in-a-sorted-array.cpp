class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        
        for(int i = 1; i < n; i++) {
            ans[0]+=(nums[i]-nums[0]);
        }
        
        for(int j = 1;j < n; j++) {
            ans[j] = ans[j-1] + (nums[j] - nums[j-1]) * j - (nums[j] - nums[j-1]) * (n-j);
        }
        
        return ans;
    }
};