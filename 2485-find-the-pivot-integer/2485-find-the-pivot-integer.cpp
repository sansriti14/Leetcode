class Solution {
public:
    int pivotInteger(int n) {
        int low = 1, high = n;
        int sum = (n * (n + 1)) / 2;
        
        while(low < high) {
            int pivot = (low + high) / 2;
            if(pivot * pivot < sum)
                low = pivot + 1;
            else high = pivot;
        }
        
        return (low * low == sum) ? low : -1;
    }
};