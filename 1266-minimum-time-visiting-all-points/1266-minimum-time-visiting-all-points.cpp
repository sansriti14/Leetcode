class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int min_time = 0;
        for(int i = 1; i < points.size(); i++) {
            min_time += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return min_time;
    }
};