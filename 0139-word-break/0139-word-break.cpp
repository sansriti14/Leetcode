class Solution {
private:
    int canSeparate(const string& s, unordered_set<string>& dictionary, int index, vector<int>& dp) {
        if(dictionary.find(s) != dictionary.end()) return 1;
        int n = s.length();
        if(n == 0) return 1;
        
        if(dp[index] != -1) return dp[index];
        
        for(int len = 1; len <= n; len++) {
            if(dictionary.count(s.substr(0, len))) {
                if(canSeparate(s.substr(len), dictionary, index + len, dp) == 1)
                    return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary (wordDict.begin(), wordDict.end());
        
        int n = s.length();
        vector<int> dp (n+1, -1);
        return canSeparate(s, dictionary, 0, dp);
    }
};