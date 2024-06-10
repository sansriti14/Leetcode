class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(begin(expected), end(expected));
        
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) count++;
        }
        
        return count;
    }
};