class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> daysOfTravel(days.begin(), days.end());
        vector<int> dp(367);
        
        for( int i = 1; i <= 365; i++) {
            dp[i] = dp[i - 1];
            if(daysOfTravel.find(i) != daysOfTravel.end()) {
                dp[i] = min({costs[0] + dp[i - 1], costs[1] + dp[max(0, i - 7)], costs[2] + dp[max(0, i - 30)]}); 
            }
        }
        
        return dp[365];
    }
};