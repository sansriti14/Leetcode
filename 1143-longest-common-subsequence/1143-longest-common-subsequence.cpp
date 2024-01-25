class Solution {
private: 
    int findLCS(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp) {
        int n = text1.length();
        int m = text2.length();
        
        if(index1 >= n || index2 >= m) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        
        if(text1[index1] == text2[index2])
            dp[index1][index2] = 1 + findLCS(text1, text2, index1 + 1, index2 + 1, dp);
        
        else dp[index1][index2] = max(findLCS(text1, text2, index1 + 1, index2, dp), findLCS(text1, text2, index1, index2 + 1, dp));
        
        return dp[index1][index2];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
        
        return findLCS(text1, text2, 0, 0, dp);
    }
};