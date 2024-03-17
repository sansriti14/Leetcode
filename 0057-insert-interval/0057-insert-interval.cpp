class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        bool inserted = false;    
        
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && newInterval[1] < intervals[i][0]) {   
                mergedIntervals.push_back(newInterval);
                mergedIntervals.push_back(intervals[i]);
                inserted = true;
            }
            
            else if (inserted || newInterval[0] > intervals[i][1]) {  
                mergedIntervals.push_back(intervals[i]);
            }
            
            else {                                             
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        if (!inserted) mergedIntervals.push_back(newInterval);
        
        return mergedIntervals;
    }
};