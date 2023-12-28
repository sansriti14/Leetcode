class Solution {
    int n;
    
private:
    int solve(int idx, char prev, int curCharFreqCount, string &s, int k, int dp[][27][11][101]) {
        if(k < 0) return 1e9;
        if(idx >= n) return 0;
        
        if(curCharFreqCount >= 10)
            curCharFreqCount = 10;
        
        if(dp[idx][prev - 'a'][curCharFreqCount][k] != -1)
            return dp[idx][prev - 'a'][curCharFreqCount][k];
        
        
        int res = 1e9;
        res = min(res, solve(idx+1, prev, curCharFreqCount, s, k-1, dp));
        
        if(s[idx] != prev)
            res = min(res, 1 + solve(idx + 1, s[idx], 1, s, k, dp));
        
        else {
            
            if(curCharFreqCount == 1 || curCharFreqCount == 9)
                res = min(res, 1 + solve(idx + 1, prev, (curCharFreqCount + 1), s, k, dp));
            
            else res = min(res, solve(idx + 1, prev, curCharFreqCount + 1, s, k, dp));
        }
        
        return dp[idx][prev - 'a'][curCharFreqCount][k] = res;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        if(n == k) return 0;
        
        bool allSame = true;
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i-1]) {
                allSame = false;
                break;
            }
        }

        if(allSame) {
            n  -= k;
            if(n == 1) return 1;
            
            return log10(n) + 1 + 1;            
        }
        
        
        int dp[n+1][27][11][101];
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 'z' + 1, 0, s, k, dp);
    }
};