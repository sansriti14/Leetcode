class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort (begin(happiness), end(happiness), greater());
        
        long long maxSum = 0;
        for (int i = 0; i < k; i++) {
            maxSum += max(happiness[i] - i, 0);
        }
        
        return maxSum;
    }
};