class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        
        for(int i = 0; i < n - 1; i++) {
            int curr_diff = heights[i + 1] - heights[i];
            if (curr_diff > 0) {
                pq.push(-curr_diff);
            }
            
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            
            if (bricks < 0) return i;
        }
        
        return n - 1;
    }
};