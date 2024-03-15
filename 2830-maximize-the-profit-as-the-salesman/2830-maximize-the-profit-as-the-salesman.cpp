class Solution {
private:
    int findMaxProfit(int index, vector<vector<int>>& offers, vector<int>& dp) {
        if(index == offers.size()) return 0;
        if(dp[index] != -1) return dp[index];
        
        int not_sell = findMaxProfit(index + 1, offers, dp);
        int next_index = offers.size();
        
        int low = index + 1;
        int high = offers.size() - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(offers[mid][0] > offers[index][1]) {
                high = mid - 1;
                next_index = mid;
            } 
            
            else low = mid + 1;
        }

        int sell = offers[index][2] + findMaxProfit(next_index, offers, dp);
        
        return dp[index] = max(sell, not_sell);
    }
    
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(begin(offers), end(offers));
        
        vector<int> dp (m, -1);
        return findMaxProfit(0, offers, dp);
    }
};