class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        
        vector<vector<int>> matrix (n, vector<int> (m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minValue = min(rowSum[i], colSum[j]);
                matrix[i][j] = minValue;
                rowSum[i] -= minValue;
                colSum[j] -= minValue;
            }
        }
        
        return matrix;
    }
};