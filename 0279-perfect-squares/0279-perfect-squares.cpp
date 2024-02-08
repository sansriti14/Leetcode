class Solution {  
    int dp[101][10001];
    
private:  
    int findMinSquares(int index, int n, vector<int>& perfectSquares) {
        if(index >= perfectSquares.size()) return 1e9;
        if(n == 0) return 0;
        
        if(dp[index][n] != -1) return dp[index][n];
        
        int not_take = findMinSquares(index + 1, n, perfectSquares);
        int take = 1e9;
        if(n - perfectSquares[index] >= 0) {
            take = min(not_take, 1 + findMinSquares(index, n - perfectSquares[index], perfectSquares));
        }
        
        return dp[index][n] = min(take, not_take);
    }
    
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for(int i = 1; i <= 100; i++) {
            perfectSquares.push_back(i * i);
        }
        
        memset(dp, -1, sizeof(dp));
        return findMinSquares(0, n, perfectSquares);
    }
};