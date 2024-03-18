class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        
        int minArrows = 0;
        int currMax;
        for (int i = 0; i < points.size();) {
            currMax = points[i][1];
            
            while (i < points.size() && points[i][0] <= currMax) {
                currMax = min(currMax, points[i][1]);
                i++;
            }
            
            minArrows++;
        }
        
        return minArrows;
    }
};