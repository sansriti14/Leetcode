class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        
        int prev_finish_time = customers[0][0] + customers[0][1];
        long long total_wait = customers[0][1];
        
        for (int i = 1; i < n; i++) {
            total_wait += customers[i][1];
            total_wait += max(0, prev_finish_time - customers[i][0]);
            
            prev_finish_time = max(prev_finish_time, customers[i][0]) + customers[i][1];
        }
        
        return (double)total_wait / n;
    }
};