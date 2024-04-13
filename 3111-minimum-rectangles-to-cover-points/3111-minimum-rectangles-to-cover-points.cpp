class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points), end(points));
        
        int count = 0;
        int prevEndPoints = -1;
        for (auto it: points) {
            if (it[0] <= prevEndPoints) continue;
            
            prevEndPoints = it[0] + w;
            count++;
        }
        
        return count;
    }
};