class Solution {
private:
    int findMaxCoins(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int max_coins = -1e9;
        for(int k = i; k < j; k++) {
            int temp = (nums[i - 1] * nums[k] * nums[j]) + findMaxCoins(i, k, nums, dp) + findMaxCoins(k + 1, j, nums, dp);
            max_coins = max(max_coins, temp);
        }
        
        return dp[i][j] = max_coins;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));
        return findMaxCoins(1, n - 1, nums, dp);
    }
};