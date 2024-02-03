class Solution {
private:
    int findMaxSum(int index, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if(index > n) return 0;
        if(dp[index] != -1) return dp[index];
        
        int max_ele = -1, max_sum = 0;
        for(int i = index; i < min(index + k, n); i++) {
            max_ele = max(max_ele, arr[i]);
            max_sum = max(max_sum, max_ele * (i - index + 1) + findMaxSum(i + 1, arr, k , dp));
        }
        
        return dp[index] = max_sum;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp (n + 1, -1);
        return findMaxSum(0, arr, k, dp);
    }
};