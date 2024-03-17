class Solution {
private:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedArray;
        vector<int> prevInterval = intervals[0];
        
        for(int i = 0; i < intervals.size(); i++) {
            if(prevInterval[1] >= intervals[i][0]) {
                prevInterval[1] = max(prevInterval[1], intervals[i][1]);
            }
            
            else {
                mergedArray.push_back(prevInterval);
                prevInterval = intervals[i];
            }
        }
        
        mergedArray.push_back(prevInterval);
        return mergedArray;
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals));
        
        return mergeOverlappingIntervals(intervals);
    }
};