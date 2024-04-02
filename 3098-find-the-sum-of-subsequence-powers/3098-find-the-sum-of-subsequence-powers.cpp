class Solution {
public:
    int mod = 1000000007;
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<long, long>>>> dp;

    long solve(int ind, int last, int size, long long mn, vector<int> &nums, int k) {
        int n = nums.size();
        if (size == k) {
            return mn % mod;
        }
        if (ind >= n)
            return 0;

        if (dp[ind][last][size].count(mn))
            return dp[ind][last][size][mn];

        long pick = LONG_MAX, notPick = LONG_MAX;
        long long diff = LONG_MAX;
        if (last != -1) {
            diff = abs(nums[ind] * 1LL - nums[last]) % mod;
        }
        
        pick = solve(ind + 1, ind, size + 1, min(mn, diff), nums, k);

        notPick = solve(ind + 1, last, size, mn, nums, k);

        return dp[ind][last][size][mn] = (pick + notPick) % mod;

    }

    int sumOfPowers(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        return solve(0, -1, 0, LONG_MAX, nums, k);

    }
};
