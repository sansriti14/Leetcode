class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        long product = 1;
        int mod = 12345;
        
        int[][] ans = new int[n][m];
        
        for(int i = 0; i < n; i++) {
            Arrays.fill(ans[i], 1);   
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (int) ((ans[i][j] * product) % mod);
                product = (product * grid[i][j]) % mod;
            }
        }

        product = 1; 
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][j] = (int) ((ans[i][j] * product) % mod);
                product = (product * grid[i][j]) % mod;
            }
        }
        
        return ans;
    }
}