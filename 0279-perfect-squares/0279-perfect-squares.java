class Solution {
    int dp[][] = new int[101][10001];
    
    private int findMinSquares(int index, int n, int perfectSquares[]) {
        if(index >= perfectSquares.length) return (int)1e9;
        if(n == 0) return 0;
        
        if(dp[index][n] != -1) return dp[index][n];
        
        int not_take = findMinSquares(index + 1, n, perfectSquares);
        int take = (int)1e9;
        if(n - perfectSquares[index] >= 0) {
            take = Math.min(not_take, 1 + findMinSquares(index, n - perfectSquares[index], perfectSquares));
        }
        
        return dp[index][n] = Math.min(take, not_take);
    }
    
    public int numSquares(int n) {
        int perfectSquares[] = new int[100];
        for(int i = 1; i <= 100; i++) {
            perfectSquares[i - 1] = i * i;
        }
        
        for(int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        return findMinSquares(0, n, perfectSquares);
    }
}
