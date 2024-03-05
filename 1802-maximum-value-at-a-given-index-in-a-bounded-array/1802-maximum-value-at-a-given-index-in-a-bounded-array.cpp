class Solution {
private:
    long long findMaxSum(int n, int index, int value) {
        int diff = max(value - index, 0);
        long long sum = (long long)(value + diff) * (value - diff + 1) / 2;
        
        diff = max(value - ((n - 1) - index), 0);
        sum += (long long)(value + diff) * (value - diff + 1) / 2;
        
        return sum - value;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        
        int low = 0, high = maxSum;
        while(low < high) {
            int mid = high - (high - low - 1) / 2;
            if(findMaxSum(n, index, mid) <= maxSum) low = mid;
            else high = mid - 1;
        }
        
        return low + 1;
    }
};