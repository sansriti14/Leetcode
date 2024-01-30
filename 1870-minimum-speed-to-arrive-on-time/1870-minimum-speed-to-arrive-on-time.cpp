class Solution {
private:
    bool isPossible (vector<int>& dist, int speed, double hour) {
        double time = 0;
        for (int i = 0; i < dist.size(); ++i) {
            time = ceil(time);
            time +=  (double)dist[i] / speed;
            if (time > hour) return false;
        }
        return true;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(!isPossible(dist, mid, hour)) low = mid + 1;
            else high = mid - 1;
        }
        
        return low <= 1e7 ? low : -1;
    }
};