class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        vector<pair<int, int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        sort(begin(jobs), end(jobs));
        sort(begin(worker), end(worker));
        
        int ans = 0;
        for(int i = 0, j = 0, maxProfit = 0; i < m; i++) {
            while(j < n && jobs[j].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            
            ans += maxProfit;
        }
        
        return ans;   
    }
};