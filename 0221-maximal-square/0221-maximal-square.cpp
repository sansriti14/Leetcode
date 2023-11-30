class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(n, vector<int> (m, 0));
        
        int max_size = 0;
        for(int col = 0; col < m; col++) {
            sum[0][col] = matrix[0][col] - '0';
            max_size = max(max_size, sum[0][col]);
        }
        
        for(int row = 0; row < n; row++) {
            sum[row][0] = matrix[row][0] - '0';
            max_size = max(max_size, sum[row][0]);
        }
        
        for(int row = 1; row < n; row++) {
            for(int col = 1; col < m; col++) {
                if(matrix[row][col] == '1') 
                    sum[row][col] = min(sum[row-1][col], min(sum[row][col-1], sum[row-1][col-1])) + 1;
                else sum[row][col] = 0;
                
                max_size = max(max_size, sum[row][col]);
            }
        }
        
        return max_size * max_size;
    }
};