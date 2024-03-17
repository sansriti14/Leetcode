class Solution {
private:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedArray;
        vector<int> prevInterval = intervals[0];
        
        for(int i = 0; i < intervals.size() - 1; i++) {
            if(prevInterval[1] < intervals[i + 1][0]) {
                mergedArray.push_back(prevInterval);
                prevInterval = intervals[i + 1];
            }
            
            else if(prevInterval[1] >= intervals[i + 1][0]) {
                prevInterval[1] = max(prevInterval[1], intervals[i + 1][1]);
            }
        }
        
        if(mergedArray.empty() || mergedArray.back()[1] < prevInterval[0]) {
            mergedArray.push_back(prevInterval);
        }
        
        return mergedArray;
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedArray;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] > newInterval[0]) {
                mergedArray.push_back(newInterval);
            }
            
            mergedArray.push_back(intervals[i]);  
        }
        
        if(mergedArray.empty()) return vector<vector<int>> {newInterval};
        if(mergedArray.size() == intervals.size()) mergedArray.push_back(newInterval);
        
        return mergeOverlappingIntervals(mergedArray);
    }
};