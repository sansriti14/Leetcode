class Solution {  
    int dp[101][10001];
    
private:  
    int findMinSquares(int index, int curr_sum, int n, vector<int>& perfectSquares) {
        if(index >= perfectSquares.size()) return 1e9;
        if(curr_sum == n) return 0;
        
        if(dp[index][curr_sum] != -1) return dp[index][curr_sum];
        
        int not_take = findMinSquares(index + 1, curr_sum, n, perfectSquares);
        int take = 1e9;
        if(curr_sum + perfectSquares[index] <= n) {
            take = min(not_take, 1 + findMinSquares(index, curr_sum + perfectSquares[index], n, perfectSquares));
        }
        
        return dp[index][curr_sum] = min(take, not_take);
    }
    
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for(int i = 1; i <= 100; i++) {
            perfectSquares.push_back(i * i);
        }
        
        memset(dp, -1, sizeof(dp));
        return findMinSquares(0, 0, n, perfectSquares);
    }
};