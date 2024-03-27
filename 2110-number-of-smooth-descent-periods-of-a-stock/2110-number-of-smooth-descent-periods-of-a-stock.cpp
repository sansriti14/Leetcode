class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 1;
        
        long long descent_days = 0;
        
        int i = 0, j = 0;
        while (j < n) {
            i = j;
            while (j < n - 1 && prices[j] - prices[j + 1] == 1) j++;
            
            int length = j - i + 1;
            descent_days += (((long long)length * (length + 1)) / 2);
            j++;
        }
        
        return descent_days;
    }
};