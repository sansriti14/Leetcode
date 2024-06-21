class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                ans += customers[i];
        }

        int sum = 0;
        int maxSum=0;
        int i = 0, j = 0;

        while (j < n) {
            if (grumpy[j] == 1) {
                sum += customers[j];
            }

            if (j - i >= minutes) {
                if(grumpy[i] == 1) {
                    sum -= customers[i];
                }
                
                i++;
            }
            
            maxSum = max(maxSum, sum);
            j++;
        }

        ans += maxSum;
        return ans;
    }
};