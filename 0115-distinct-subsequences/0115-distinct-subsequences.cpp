class Solution {
private:
    int countSubsequences(int s_index, int t_index, string& s, string& t, vector<vector<int>>& dp) {
        if(t_index == t.length()) return 1;
        if(s_index == s.length()) return 0;
        
        if(dp[s_index][t_index] != -1) return dp[s_index][t_index];
        
        int not_pick = 0, pick = 0;
        
        not_pick = countSubsequences(s_index + 1, t_index, s, t, dp);
        
        if(s[s_index] == t[t_index]) {
            pick = countSubsequences(s_index + 1, t_index + 1, s, t, dp);
        }
        
        return dp[s_index][t_index] = pick + not_pick;
    }
    
public:
    int numDistinct(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        
        vector<vector<int>> dp (s_length, vector<int> (t_length, -1));
        return countSubsequences(0, 0, s, t, dp);
    }
};