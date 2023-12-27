class Solution {
private:
    int findMinTime(string& colors, vector<int>& neededTime, int index, char prev_color, int prev_time, vector<int>& dp) {
        if(index < 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        if(colors[index] == prev_color) {
            return dp[index] = min(neededTime[index], prev_time) + findMinTime(colors, neededTime, index - 1, colors[index], max(neededTime[index], prev_time), dp);
        }
        
        else {
            return dp[index] = findMinTime(colors, neededTime, index - 1, colors[index], neededTime[index], dp);
        }
    }
    
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return findMinTime(colors, neededTime, n-1, 'A', neededTime[n-1], dp);
    }
};