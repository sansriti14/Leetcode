class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), comparator);
        
        vector<int> prevInterval = intervals[0];
        int minRemovals = -1;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(prevInterval[1] > intervals[i][0]) minRemovals++;
            
            else prevInterval = intervals[i];
        }
        
        
        return minRemovals;
    }
};