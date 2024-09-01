class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if ((m * n) != size) return {};
        
        vector<vector<int>> ans (m, vector<int> (n));
        
        int row = 0, col = 0;
        
        for (int i = 0; i < size; i++) {
            ans[row][col++] = original[i];
            if (col == n) row++, col = 0;
        }
        
        return ans;
    }
};