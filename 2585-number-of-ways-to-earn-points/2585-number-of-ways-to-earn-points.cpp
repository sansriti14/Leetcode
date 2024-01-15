class Solution {
private:
    int mod = 1e9 + 7; 
    
    int findWays(int index, int target, vector<vector<int>>& types, vector<vector<int>>& dp) {
        int n = types.size();
        
        if(target == 0) return 1;
        if(index == n) return 0;
        
        if(dp[index][target] != -1) return dp[index][target];

        int count = types[index][0];
        int marks = types[index][1];
        
        long long ways = 0;
        for(int i = 0; i <= count* marks; i += marks) {
            if(target - i >= 0) {
                ways = (ways + findWays(index + 1, target - i, types, dp)) % mod;
            }
        }
        
        return dp[index][target] = ways % mod;
    }
    
public:    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n, vector<int>(target + 100 , -1)) ; 
        return findWays(0 , target, types, dp) ;
    }
};