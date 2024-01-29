class Solution {
private:
    int timeRequired(int speed, vector<int>& piles) {
        int time = 0;
        for(int i = 0; i < piles.size(); i++) {
            time += (piles[i] + speed - 1) / speed;
        }
        
        return time;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            int time = timeRequired(mid, piles);
            if(time > h) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};