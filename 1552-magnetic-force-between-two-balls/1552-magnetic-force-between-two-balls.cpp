class Solution {
private:
    int findNumBalls(vector<int>& position, int minDistance) {
        int numBalls = 1, prev = position[0];
        for(int curr = 1; curr < position.size(); curr++) {
            if(position[curr] - prev >= minDistance) {
                numBalls++;
                prev = position[curr];
            }
        }
        
        return numBalls;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position), end(position));
        int low = 0, high = position[n - 1] - position[0];
        
        while(low < high) {
            int mid = high - (high - low) / 2;
            int numBalls = findNumBalls(position, mid);
            if(numBalls >= m) low = mid;
            
            else high = mid - 1;
        }
        
        return low;
    }
};