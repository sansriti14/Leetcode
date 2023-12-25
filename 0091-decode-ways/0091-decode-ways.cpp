class Solution {
private:    
    int decode(int i, string &s, vector<int> &dp) {
        if(s[i] == '0') return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        
        int n = s.size();
        int count = decode(i+1, s, dp);
        if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1]<'7')) {
            count += decode(i+2, s, dp);
        }
        
        return dp[i] = count;
    }
    
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        dp[n] = 1;
        return s.empty()? 0 : decode(0, s, dp);   
    }
};