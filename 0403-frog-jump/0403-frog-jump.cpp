class Solution {
private:
    bool solve(int curr_index, int last_jump, vector<int>& stones, vector<vector<int>>& dp) {
        int n = stones.size();
        
        if(curr_index == n-1) return true;
        if(curr_index >= n) return false;
        
        if(dp[curr_index][last_jump] != -1) return dp[curr_index][last_jump];
        
        bool ans = false;
        
        for(int i = -1; i < 2; i++) {
            int next_jump = last_jump + i;
            
            if(next_jump > 0) {
                int next_index = lower_bound(stones.begin(), stones.end(), stones[curr_index] + next_jump) - stones.begin();
                if(next_index >= n || stones[next_index] != stones[curr_index] + next_jump) 
                    continue;

                ans = solve(next_index, next_jump, stones, dp) || ans;
            }
        }
        
        return dp[curr_index][last_jump] = ans;
    }
    
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        
        int n = stones.size();
        vector<vector<int>> dp (n, vector<int> (n+1, -1));
        return solve(0, 0, stones, dp);
    }
};