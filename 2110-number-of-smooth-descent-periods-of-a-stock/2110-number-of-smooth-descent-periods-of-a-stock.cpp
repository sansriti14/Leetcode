class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 1;
        
        long long curr = 0;
        long long descent_days = 0;
        
        for (int i = 0; i < n; i++) {
            if (i != 0 && prices[i - 1] - prices[i] == 1) curr++;
            else curr = 1;
            
            descent_days += curr;
        }
        
        return descent_days;
    }
};