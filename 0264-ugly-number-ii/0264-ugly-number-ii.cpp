class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0; 
        if(n == 1) return 1;
        int temp2 = 0, temp3 = 0, temp5 = 0; 
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = min(dp[temp2] * 2, min(dp[temp3] * 3, dp[temp5] * 5));
            if(dp[i] == dp[temp2] * 2) temp2++; 
            if(dp[i] == dp[temp3] * 3) temp3++;
            if(dp[i] == dp[temp5] * 5) temp5++;
        }
        return dp[n - 1];
    }
};
