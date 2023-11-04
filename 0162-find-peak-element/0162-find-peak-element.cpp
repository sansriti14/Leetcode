class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;

        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(mid == 0) return high;
            
            else if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

            else if(arr[mid-1] < arr[mid]) low = mid+1;
            else high = mid - 1;
        }

        return -1;
    }
};