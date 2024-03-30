class Solution {
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;
    int mod = 1e9 + 7;

    int findSumOfPowers(int currIndex, int prevIndex, int k, int currDiff, vector<int>& nums) {
        if (k == 0) return currDiff % mod;
        if (currIndex == nums.size()) return 0;
        
        if (dp[currIndex][prevIndex][k].count(currDiff))
            return dp[currIndex][prevIndex][k][currDiff];

        int notTake = findSumOfPowers(currIndex + 1, prevIndex, k, currDiff, nums);
        
        int take = 0;
        if (prevIndex == -1) {
            take = findSumOfPowers(currIndex + 1, currIndex, k - 1, currDiff, nums);
        } else {
            take = findSumOfPowers(currIndex + 1, currIndex, k - 1, min(currDiff, abs(nums[currIndex] - nums[prevIndex])), nums);
        }

        return dp[currIndex][prevIndex][k][currDiff] = (take % mod + notTake % mod) % mod;
    }

public:
    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return findSumOfPowers(0, -1, k, 1e9, nums);
    }
};

