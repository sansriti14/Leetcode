class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    
    vector<unordered_map<int, int>> dp(n);
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if((long)nums[i] - (long)nums[j] > INT_MAX || (long)nums[i] - (long)nums[j] < INT_MIN) continue;
            
            int diff = nums[i] - nums[j];
            dp[i][diff] += 1;
            if(dp[j].find(diff) != dp[j].end()) {
                dp[i][diff] += dp[j][diff];
                count += dp[j][diff];
            }
        }
    }
    
    return count;
    }
};