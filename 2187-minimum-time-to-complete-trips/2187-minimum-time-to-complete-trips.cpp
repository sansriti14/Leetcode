class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(begin(time), end(time));
        long long low = 1, high = 1e14;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            long long num_trips = 0;
            for(auto &it: time) {
                num_trips += (mid / it);
            }
            
            if(num_trips < totalTrips) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};