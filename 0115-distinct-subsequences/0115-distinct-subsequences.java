class Solution {
    private int countSubsequences(int s_index, int t_index, String s, String t, int dp[][]) {
        if(t_index == t.length()) return 1;
        if(s_index == s.length()) return 0;
        
        if(dp[s_index][t_index] != -1) return dp[s_index][t_index];
        
        int not_pick = 0, pick = 0;
        
        not_pick = countSubsequences(s_index + 1, t_index, s, t, dp);
        
        if(s.charAt(s_index) == t.charAt(t_index)) {
            pick = countSubsequences(s_index + 1, t_index + 1, s, t, dp);
        }
        
        return dp[s_index][t_index] = pick + not_pick;
    }
    
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        
        int dp[][] = new int[n][m];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) 
                dp[i][j] = -1;
        }
        
        return countSubsequences(0, 0, s, t, dp);
    }
}