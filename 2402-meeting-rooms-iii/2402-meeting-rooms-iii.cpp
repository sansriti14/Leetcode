class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> bookings(n, 0);
        vector<long long> endTimes(n, 0);
        sort(begin(meetings), end(meetings));

        for(int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            
            bool hasRoom = false;
            int nextAvailable = -1;
            long long waitDuration = 1e18;
            
            for(int j = 0; j < n; j++){
                if(endTimes[j] < waitDuration) {
                    waitDuration = endTimes[j];
                    nextAvailable = j;
                }
                
                if(endTimes[j] <= start) {
                    hasRoom = true;
                    bookings[j]++;
                    endTimes[j] = end;
                    break;
                }
            }
            
            if(!hasRoom) {
                bookings[nextAvailable]++;
                endTimes[nextAvailable] += (1ll * (end - start));
            }
        }
        
        int max_bookings = -1, room = -1;
        for(int i = 0; i < n; i++){
            if(bookings[i] > max_bookings) {
                max_bookings = bookings[i];
                room = i;
            }
        }
        
        return room;
    }
};