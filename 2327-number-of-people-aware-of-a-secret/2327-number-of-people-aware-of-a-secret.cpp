class Solution {
private:
    int countPeople(int discoveredOnDay, int n, int delay, int forget, vector<int>& dp) {
        if(dp[discoveredOnDay] != -1) return dp[discoveredOnDay];
        
        long long count = 0;
        
        count++;
        
        if(discoveredOnDay + forget <= n) count--;
        
        int mod = 1e9 + 7;
        for(int day = discoveredOnDay + delay; day < min(discoveredOnDay + forget, n + 1); day++) {
            count = (count + countPeople(day, n, delay, forget, dp)) % mod;
        }
        
        return dp[discoveredOnDay] = count;
    }
    
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp (n + 1, -1);
        
        return countPeople(1, n, delay, forget, dp);
    }
};