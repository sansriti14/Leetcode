class Solution {
private:
    bool solve(int curr_index, int last_jump, vector<int>& stones, vector<vector<int>>& dp) {
        int n = stones.size();
        
        if(curr_index == n-1) return true;
        
        if(dp[curr_index][last_jump] != -1) return dp[curr_index][last_jump];
        
        bool ans = false;
        for(int next_index = curr_index+1; next_index < n; next_index++) {
            if(stones[next_index] - stones[curr_index] > last_jump + 1) break;
            
            for(int i = -1; i < 2; i++) {
                if(stones[next_index] - stones[curr_index] == last_jump + i) {
                    ans = solve(next_index, last_jump + i, stones, dp) || ans;
                }
            }
        }
        
        return dp[curr_index][last_jump] = ans;
    }
    
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        
        int n = stones.size();
        vector<vector<int>> dp (n, vector<int> (n+1, -1));
        return solve(1, 1, stones, dp);
    }
};